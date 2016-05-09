---
ID: 461
post_title: 'A* Algoritması (A yıldız arama algoritması)'
author: farukcan
post_date: 2016-05-09 19:17:00
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/algoritmalar/2016/05/a-algoritmasi-a-yildiz-arama-algoritmasi/
published: true
dsq_thread_id:
  - "4812561797"
dsq_needs_sync:
  - "1"
---
<strong>Amacı</strong> : Bir düğümden, diğer düğüme en az maliyetli çözümü bulmak

<strong>Türü : </strong>Arama Algoritması, Sezgisel Algoritma (Yapay zeka)

<strong>Kâşifleri</strong> : Nils Nilsson,Bertram Raphael , Peter E. Hart

<strong>Kullanım yerleri :</strong>
<ul>
	<li>Yol bulma</li>
	<li>Oyunlarda aktörün hedefe doğru izleyeceği yolların tespiti</li>
	<li>Gezgin satıcı probleminin çözümü</li>
	<li>Labirentten en kısa çıkışı bulma</li>
</ul>
&nbsp;

<strong>f(x)</strong> : durum fonksiyonu. Az olması, o durumun daha az maliyetli olduğunu belirtir.
<pre>f(x) = g(x) + h(x)</pre>
<strong>g(x) :</strong> Başlangıç durumuna göre maliyetimiz.

<strong>h(x) :</strong> Bitiş duruma olan sezgisel maliyet.