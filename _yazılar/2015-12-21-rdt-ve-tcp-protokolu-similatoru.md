---
ID: 439
post_title: RDT ve TCP Protokolü Similatörü
author: farukcan
post_date: 2015-12-21 22:42:09
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/algoritmalar/2015/12/rdt-ve-tcp-protokolu-similatoru/
published: true
dsq_thread_id:
  - "4423352288"
---
<iframe src="http://farukcan.net/examples/rdt.html" height=500 width="100%"></iframe>

<pre lang="javascript">
    var checksum=false;
    var seqnumenabled = false;
    var onlyack = false;
    var seqnum = 0;
    var rtd30 = false;
    var seqnumold = seqnum;
    var tcp = false;

    function send(){

        delay();

        checksum = $("#checksum").is(":checked");
        seqnumenabled = $("#seqnum").is(":checked");
        onlyack = $("#onlyack").is(":checked");
        rtd30 = $("#rtd30").is(":checked");;
        tcp = $("#tcp").is(":checked");;

        if(!checksum)
            return tabloyaekle($("#datawillsend").val(),"==>",recieve());
        else{
            if(seqnumenabled){
                if(onlyack){
                    if(rtd30){

                        if(tcp){
                            var recieved = recieve();
                            var crecieved = checksummed(recieved);
                            var sended =  $("#datawillsend").val();
                            var csended = checksummed(sended);
                            if(kayboldumu()){

                                tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","=[KAYIP]>","");

                                setTimeout(send,$("#time").val());

                            }else{

                                tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","==> ","["+seqnum+"] "+recieved+"("+csended+"/"+crecieved+")");

                                seqnumold = seqnum;

                                sendACKforTCP(csended==crecieved)


                                setTimeout(function () {
                                    if(seqnumold == seqnum)
                                        send();
                                },$("#time").val());


                            }

                        }
                        else{

                            var recieved = recieve();
                            var crecieved = checksummed(recieved);
                            var sended =  $("#datawillsend").val();
                            var csended = checksummed(sended);

                            if(kayboldumu()){

                                tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","=[KAYIP]>","");

                                setTimeout(send,$("#time").val());

                            }else{

                                tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","==> ","["+seqnum+"] "+recieved+"("+csended+"/"+crecieved+")");

                                seqnumold = seqnum;

                                sendACKwithCS2withLoss(csended==crecieved)


                                setTimeout(function () {
                                    if(seqnumold == seqnum)
                                        send();
                                },$("#time").val());


                            }

                        }



                    }else{

                        var recieved = recieve();
                        var crecieved = checksummed(recieved);
                        var sended =  $("#datawillsend").val();
                        var csended = checksummed(sended);

                        tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","==> ","["+seqnum+"] "+recieved+"("+csended+"/"+crecieved+")");

                        seqnumold = seqnum;

                        sendACKwithCS2(csended==crecieved);

                        setTimeout(function () {
                            if(seqnumold == seqnum)
                                send();
                        },$("#time").val());

                    }


                }else{
                    var recieved = recieve();
                    var crecieved = checksummed(recieved);
                    var sended =  $("#datawillsend").val();
                    var csended = checksummed(sended);

                    tabloyaekle("["+seqnum+"] "+sended+"("+csended+")","==> ","["+seqnum+"] "+recieved+"("+csended+"/"+crecieved+")");

                    if(csended==crecieved){
                        sendACKwithCS();
                    }else{
                        sendNACKwithCS();
                    }
                }




            }else{
                var recieved = recieve();
                var crecieved = checksummed(recieved);
                var sended =  $("#datawillsend").val();
                var csended = checksummed(sended);

                tabloyaekle(sended+"("+csended+")" , " ==>" , recieved+"("+csended+"/"+crecieved+")");


                if(csended==crecieved){
                    sendACK();
                }else{
                    sendNACK();
                }

            }

        }
    }

    function sendACK(){
        delay();

        if(bozuldumu()){
            tabloyaekle("?NACK?"," <==  ","ACK");
            send();
            return tabloyaekle("","","! HATA : duplikasyon tespit edildi ?");
        }
        else
            return tabloyaekle("ACK"," <==  ","ACK") + tabloyaekle("","BiTTi","");
    }
    function sendNACK(){
        delay();

        if(bozuldumu()){
            tabloyaekle("?ACK?"," <==  ","NACK");
            return tabloyaekle("","","! HATA : istenen veri alınamadı ?");
        }
        else
            return tabloyaekle("NACK"," <==  ","NACK");
        return send();
    }

    function sendACKwithCS(){
        delay();

        if(bozuldumu()){
            if(checksumdogrumu()){
                tabloyaekle("NACK (A)"," <==  ","ACK (A)");
                tabloyaekle("checksum eşleşmedi","   ","");
                tabloyaekle("","","! DÜZELTİLDİ : duplikasyon tespit edildi?");
                send();
            }else{
                tabloyaekle("NACK (N)"," <==  ","ACK (A)");
                send();
            }
        }else{
            tabloyaekle("ACK (A)"," <==  ","ACK (A)");
            seqnum++;
            tabloyaekle("","BiTTi","");
        }
    }

    function sendNACKwithCS(){
        if(bozuldumu()){
            if(checksumdogrumu()){
                tabloyaekle("ACK (N)"," <==  ","NACK (N)");
                tabloyaekle("checksum eşleşmedi","   ","");
                send();
            }else{
                tabloyaekle("ACK (A)"," <==  ","NACK (N)");
                seqnum++;
                return tabloyaekle("","","! HATA : istenen veri alınamadı ?");
            }
        }else{
            tabloyaekle("NACK (N)"," <==  ","NACK (N)");
            send();
        }
    }

    function sendACKwithCS2(checksum){
        delay();

        if(bozuldumu()){
            {
                tabloyaekle("["+seqnum+"] ACK (N)"," <==  ","["+seqnum+"] ACK (A)");
                tabloyaekle("checksum eşleşmedi","   ","");
                send();
                tabloyaekle("","","! DÜZELTİLDİ : duplikasyon tespit edildi ?");
            }
        }else{
            if(checksum){
                tabloyaekle("["+seqnum+"] ACK (A)"," <==  ","["+seqnum+"] ACK (A)");
                seqnum++;
                tabloyaekle("","BiTTi","");
            }
        }


    }

    function sendACKwithCS2withLoss(checksum){
        delay();

        if(kayboldumu()){
            tabloyaekle(""," <[KAYIP]=  ","["+seqnum+"] ACK");
        }else{
            sendACKwithCS2(checksum);
        }

    }

    function sendACKforTCP(checksum){
        delay();
        if(kayboldumu()){
            tabloyaekle(""," <[KAYIP]=  ","["+seqnum+"] ACK");
        }else{
            if(bozuldumu()){
                {
                    if(checksum) {
                        tabloyaekle("[" + seqnum + "] ACK (N)", " <==  ", "[" + seqnum + "] ACK (A)");
                        tabloyaekle("checksum eşleşmedi", "   ", "");
                        send();
                    }
                }
            }else{
                if(checksum){
                    tabloyaekle("["+seqnum+"] ACK (A)"," <==  ","["+seqnum+"] ACK (A)");
                    seqnum+=$("#datawillsend").val().length;
                    tabloyaekle("","BiTTi","");
                }
            }
        }
    }

    function checksummed(t){
        var csum = 0;
        for(var i= 0;i<t.length;i++){
                if(t[i]=="1") csum++;
        }
        return csum;
    }
    function recieve(){
        var t = $("#datawillsend").val();
        for(var i= 0;i<t.length;i++){
            if(bozuldumu()){
                if(t[i]=="0") t = t.replaceAt(i, "1");
                else  t = t.replaceAt(i, "0");;
            }
        }
        return t;
    }

    
    function bozuldumu(){
        return Math.random()*100<parseInt($("#bozulma").val());
    }
    function kayboldumu(){
        return Math.random()*100<parseInt($("#kayip").val());
    }
    function checksumdogrumu(){
        return Math.random()*100<50;
    }
    function tabloyaekle(a,b,c){
        $("#tablo").append("<tr><td>"+Date.now().toTime()+"</td></td><td>"+a+"</td><td>"+b+"</td><td>"+c+"</td></tr>");
    }
    
    function temizle(){
        $("#tablo").html("<tr><th>GÖNDEREN</th><th>ARA</th><th>ALAN</th></tr>");
        seqnum = 0;
    }
    String.prototype.replaceAt=function(index, character) {
        return this.substr(0, index) + character + this.substr(index+character.length);
    }

    Number.prototype.toTime = function(){
        return Math.floor(this%3600000/60000)+":"+ Math.floor(this%60000/1000) + ':' + this%1000
    };

    function delay(){
        sleep(parseInt($("#thr").val()));
    }
    function sleep(milliseconds) {
        var start = new Date().getTime();
        for (var i = 0; i < 1e7; i++) {
            if ((new Date().getTime() - start) > milliseconds){
                break;
            }
        }
    }


</pre>