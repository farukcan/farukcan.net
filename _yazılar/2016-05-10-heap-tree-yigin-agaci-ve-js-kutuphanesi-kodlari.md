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
  http://farukcan.net/genel/2016/05/heap-tree-yigin-agaci-ve-js-kutuphanesi-kodlari/
published: true
---
İkili bir ağaç yapısıdır. Kök hariç , her düğümün bir ebeveyni vardı. Her ebeveyninde en fazla 2 çocuğu vardı.

2 türü vardır ; Minimum heap, Maximum heap.
<h2>Kuralları</h2>
<ul>
	<li>Eğer minimum heap ise, ebeveyn çocuklarında daima küçük olmalıdır. Maximum heapde tam tersi geçerlidir.</li>
	<li>Çocuklar arası ilişki yoktur.</li>
	<li>Bir düğümün ebeveyninin indeksi, kendi indeksinin yarısıdır. (yani 5. düğümün ebeveyn 2.düğümdür)</li>
	<li>Tek indeks sahip düğüm sağda, çift indekse sahip düğüm soldadır. (yani 3&gt;sağ ; 4&gt;sol)</li>
	<li>Ebeveyninin indeksinin 2 katı sol çocuğun indeksi, 2 katının 1 fazlası sağ çocuğun indeksidir. (2nin sol çocuğu 4, sağ çocuğu 5'tir)</li>
	<li>Yeni eklenen düğüm, her zaman ağacın en alt sol tarafına eklenir. (Yani dizinin en sağına eklenir)</li>
</ul>
<pre>p : ebeveyn indeksi
x : herhangi bir düğümün indeksi
sol : sol çocuk indeksi
sağ : sağ çocuk indeksi
---
sol = 2*p
sağ = 2*p+1
--
p = x/2
--
x%2 = 1 ise =&gt; sağdadır.
x%2 = 0 ise =&gt; soldadır.</pre>