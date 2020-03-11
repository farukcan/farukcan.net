ID: 427
title: Perceptron Eğitimi - Yapay Sinir Ağları
author: farukcan
post_excerpt: ''
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - yapay zeka
  - makine öğrenmesi
  - yapay sinir ağları
dsq_thread_id:
  - '4381511103'
date: 2015-12-06 23:46:51
---
<iframe src="/html/ysa.html" width="100%" height="700"></iframe>
{% codeblock lang:js %}
    var w, // ağırlık
            A, B, // girişler
            dA,dB; // istenenler


    function calculate(){
        $('#console').html('');
        MAXLOOP=Number($("#maxloop").val());

        var data = [];
        data.push(A);
        data.push(B);
        var beklenen = [];
        beklenen.push(dA);
        beklenen.push(dB);

        var c=Number($("#c").val());
        var k=1; // itarasyon ks
        var E=1; //ERROR
        var o=0; //sign(toplam)
        var p=0; // adım sayısı
        while (E>0 && p < MAXLOOP) {

            E = 0;
            p++;
            if (p == MAXLOOP - 1){
                alert("MAX LOOP Aşıldı");
                break;
            }

            for (var j = 0; j < data.length; j++) {
                o = sign(toplam(data[j], w));

                if (o == beklenen[j]) {
                    //ok
                } else {

                    for (var i = 0; i < w.length; i++) {
                        w[i] = w[i] + c * (beklenen[j] - o) * data[j][i] / 2;
                    }
                }

                E = E + 1 / 2 * (Math.pow(beklenen[j] - o, 2));

            }
            k++;

            print("<br>w = "+w.toString()+"[ E= "+E+" ]");


        }

        alert("w = "+w.toString());

    }

    function toplam(x,w){
        var toplam=0;
        for(key in w){
            toplam+=w[key]*x[key];
        }
        return toplam;
    }

    function sign(x){
        return Math.sign(x);
    }

    function f(x){
        return 2/(1+Math.exp(-1*x))-1;
    }

{% endcodeblock %}