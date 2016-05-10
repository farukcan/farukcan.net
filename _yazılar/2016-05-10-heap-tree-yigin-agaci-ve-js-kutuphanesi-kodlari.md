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
---
İkili bir ağaç yapısıdır. Kök hariç , her düğümün bir ebeveyni vardı. Her ebeveyninde en fazla 2 çocuğu vardı.

2 türü vardır ; Minimum heap, Maximum heap.
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