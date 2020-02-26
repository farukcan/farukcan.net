---
ID: 467
post_title: >
  Heap Tree (Yığın Ağacı) ve JS
  kütüphanesi kodları
author: farukcan
post_date: 2016-05-10 13:53:05
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/algoritmalar/2016/05/heap-tree-yigin-agaci-ve-js-kutuphanesi-kodlari/
published: true
dsq_thread_id:
  - "4814711052"
---
İkili bir ağaç yapısıdır. Kök hariç , her düğümün bir ebeveyni vardı. Her ebeveyninde en fazla 2 çocuğu vardı.

2 türü vardır ; Minimum heap, Maximum heap.
<h2>Amacı</h2>
En yüksek performansta, bir diziden en küçük ve en büyük değerleri teker teker sırasıyla çekebilmektir. Bu dizi, sıralı değildir. Ancak ilk elemanı(kökü) daima en büyük veya en küçük elemandır.
<h2>Kuralları</h2>
<ul>
	<li>Eğer minimum heap ise, ebeveyn çocuklarında daima küçük olmalıdır. Maximum heapde tam tersi geçerlidir.</li>
	<li>Çocuklar arası ilişki yoktur.</li>
	<li>Tek indeks sahip düğüm solda, çift indekse sahip düğüm sağdadır. (yani 3&gt;sol; 4&gt;sağ)</li>
	<li>Ebeveyninin indeksinin 2 katının 1 fazlası sol çocuğun indeksi, 2 katının 2 fazlası sağ çocuğun indeksidir. (2nin sol çocuğu 5, sağ çocuğu 6'tir)</li>
	<li>Yeni eklenen düğüm, her zaman ağacın en alt sol tarafına eklenir. (Yani dizinin en sağına eklenir)</li>
</ul>
<pre>NOT : Kökün indeksi 0'dır.

p : ebeveyn indeksi
x : herhangi bir düğümün indeksi
sol : sol çocuk indeksi
sağ : sağ çocuk indeksi
---
sol = 2*p+1
sağ = 2*p+2
--
x%2 = 0 ise =&gt; sağdadır.
p = x / 2 - 1
x%2 = 1 ise =&gt; soldadır.
p = (x - 1) / 2</pre>
<h2>Ekleme</h2>
<ul>
	<li>Değer dizinin sonuna(en sağına), eklenir.</li>
	<li>Eklenen değer ebeveyni ile kıyaslanır. Ebeveyninden küçük ise, onunla yer değiştiri ve bu işlemin aynısı ebeveynlerininin ebeveynleri ilede yapılır.</li>
</ul>
<h2>Çıkarma</h2>
<ul>
	<li>Heapda, daima kök değer çıkartılır. Yani dizinin ilk elemanı çıkartılır.</li>
	<li>Çıkartılan bu değer ile yeni ağaç oluşur.</li>
	<li>Bu ağaçta kökten başlayan, çocuğu olmayan düğüme kadar, en küçük değere sahip çocuk ile kıyaslanır, eğer en küçük çocuktan büyük ise yer değiştirilir. Yer değiştirilen çocuk ile aynı işlem ağacın o dalı boyunca tekrarlanır.</li>
</ul>
Bu işlemi yapan, yeni yazdığım bir Heap sınıfı.
<pre lang="javascript">
function Heap(sortFunc){
    this.nodes = [];
    this.sortFunc= sortFunc || function(a,b){return a-b;};

    this.func = function(a,b){
            return this.sortFunc(a,b) < 0;
    }
}



Heap.prototype = {
    add : function(e){
        var x = this.nodes.length;
        this.nodes.push(e);
        var p = this.parent(x);

        // heapify2up
        while(this.func(this.nodes[x],this.nodes[p]) && x!=0){
            this.nodes[x]=this.nodes[p];
            this.nodes[p]=e;

            x=p;
            e = this.nodes[x];
            p=this.parent(x);
        }

        return this.nodes;

    },
    get : function(){
        var r = this.nodes.shift();

        //heapify2down
        var x = 0;
        var childs = this.childs(x);
        var min;
        while(childs.length!=0){
            min=childs[0];
            if(childs.length==2 && !this.func(this.nodes[childs[0]],this.nodes[childs[1]])){
                min = childs[1];
            }

            if(this.func(this.nodes[min],this.nodes[x])){
                var temp = this.nodes[x];
                this.nodes[x] = this.nodes[min];
                this.nodes[min] = temp;
                x = min;
                childs = this.childs(x);
            }
            else childs=[]
        }
        return r;
    },
    isEmpty : function(){
        return this.nodes.length==0;
    },
    parent : function(x){
        if(this.right(x)) return x/2-1;
        return (x-1)/2;
    },
    childs : function(x){
      var a = [];
      if(this.nodes[2*x+1]){
          a.push(2*x+1);
          if(this.nodes[2*x+2])
              a.push(2*x+2);
      }
      return a;
    },
    right : function(x){
        return x%2==0;
    }
};


</pre>
&nbsp;