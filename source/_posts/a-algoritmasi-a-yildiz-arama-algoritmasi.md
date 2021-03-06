---
ID: 461
title: 'A* Algoritması (A yıldız arama algoritması)'
author: farukcan
date: 2016-05-09 19:17:00
post_excerpt: ""
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - javascript
  - oop
  - yapay zeka
  - arama
  - sezgisel
dsq_thread_id:
  - "4812561797"
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
<h2>Algoritma</h2>
<pre>OPEN -&gt; // fCost'a göre sıralı dizi

OPEN.ekle(başlangıç_düğümü)

DÖNGÜ - OPEN dizi boyutu 0 olmadığı müddetçe
    şuanki_düğüm &lt;- OPEN.ilk elemanı
    OPEN.sil(şuanki düğüm)
    EĞER şuanki_düğüm, hedef düğüm ise
        DÖNGÜden çık // HEDEFE ULAŞTI
    şuanki_düğüm.closed=true
    şuanki_düğüm.gCostHesapla()
    komşular = şuanki_düğüm.komşular
    DÖNGÜ komşu &lt;- komşular
        EĞER komşu.closed ise SONRAKİ_KOMŞUYA_GEÇ
        maliyet = şuanki_düğüm.gCost + komşuya_uzaklık
        komşu.gCostHesapla()
        EĞER komşu.OPENdaDeğilse veya maliyet&lt;komşu.gCost ise
            komşu.gCost = maliyet
            komşu.hCostHesapla()
            komşu.ebeveyn = şuanki_düğüm
            EĞER komşu.OPENdaDeğilse
                OPEN.ekle(komşu)
OPEN dizi boyutu 0 olduğu için DÖNGÜden çıkıldıysa // HEDEFE ULAŞAMADI</pre>

<h2>Javascript Kodu</h2>
FIND (Yol bulmayı başlat) <br>
RELOAD (Gridi yeniden yükle) <br>
ilk tık -> başlangıç karesi<br>
2. tık -> hedef kare<br>
sonraki tıklar -> engel oluştur<br>
<p data-height="927" data-theme-id="dark" data-slug-hash="dMawLJ" data-default-tab="result" data-user="farukcan" data-embed-version="2" class="codepen">See the Pen <a href="http://codepen.io/farukcan/pen/dMawLJ/">A* Algoritması</a> by farukcan (<a href="http://codepen.io/farukcan">@farukcan</a>) on <a href="http://codepen.io">CodePen</a>.</p>
<script async src="//assets.codepen.io/assets/embed/ei.js"></script>
