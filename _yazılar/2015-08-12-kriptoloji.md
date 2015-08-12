---
ID: 252
post_title: Kriptoloji
author: farukcan
post_date: 2015-08-12 12:20:59
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/guvenlikhack/2015/08/kriptoloji/
published: true
dsq_thread_id:
  - "4025251374"
---
<strong>Kriptoloji (Şifreleme Bilimi)</strong>
<ol>
	<li>Kriptografi :<em> Şifreleyerek bilgilerimizi gizlemektir.</em></li>
	<li>Kriptoanaliz : <em>Başkaların şifreli metinlerini inceleyerek, metni elde etmektir</em></li>
</ol>
<strong>Encode :</strong> Farklı formata dönüştürme. Utf8 -&gt; Base64,Hex

<strong>Plaintext</strong> P: Metin

<strong>Ciphertext</strong> C: Şifrelenmiş Metin

<strong>Key </strong>K: Şifreleyen anahtar. Şifre

<strong>Cipher</strong> : Şifreyici

<strong>Encrypt : </strong>Metni şifreleme fiili

<strong>Decrypt </strong>: Şifrelenmiş metni çözme fiili ( - deşifre )

<strong>Base64 </strong>: Verilerin 2^6 lik, 64 karakterle ifadesini sağlar. Bu biçimi binaryler ve ASCIIler çevrilebilmektedir. Genelde sonlarında = veya == bulunur. Herkes tarafından bilinir ve encoding/decoding yapılabilir.
<h2>Kerckhoff Prensibi</h2>
Bir kripto sisteminin güvenliği algoritmayı gizli tutmaya bağlı olmamalıdır. Sadece Key'in gizliliğini bağlı olmalı. Çünkü algoritmayı değiştirmek zordur.
<h2>XOR</h2>
Farklı olma durumu arayan kapıdır. 00=0 , 01=1 , 10=1 , 11=0
<pre>A xor B = A</pre>
<pre>A xor A = 0</pre>
<pre>A xor B xor A = B</pre>
Son kısma dikkat <em>P xor K xor K = P </em>oluyor. Yani XOR ile şifrelemede Key iki defa kullanılamaz.
<pre>P1 xor K = C1</pre>
<pre>P2 xor K = C2</pre>
olsun.  O zaman
<pre>C1 xor C2 = P1 xor P2</pre>
Yani Şifrelenmiş iki metni'nin xor, Şifrelenmemiş hallerinin iç içe geçmiş hali olacaktır. Eğer bunu bir resimde yapsaydık, iki resmi içi içe görürdük.
<h3>OTP (Vernam)</h3>
<strong>One-time pad</strong> (Tek kullanımlık Şerit): P xor K = C 'nin tektek her bit için kullanıldığı. P ve K şeritlerini alıp C şeridi veren şifreleme türüdür. Sadece bir defa kullanılmalıdır. Kırılmasının imkansız olduğu kanıtlanmıştır.
<h2>Rastgelelilik</h2>
Rastgelelilik bir teoridir. Birşeyin rastgele olmasının sebebi, onu hesaplayamamız veya nasıl hesaplanacağını bilmemizdir.

<strong>Pseudo Random Number Generator : </strong>

Bu algoritma mod fonksiyonun geri döndürülemezlik özelliğini kullanır.
<pre><strong></strong>Xi+1 = (a.Xi+c)modM;</pre>
Bu C'dilin random sayı üretme algoritmasıdır. a ve c sabit değerdir. (asal sayı olması önerilir) Xi önceki random üretilen sayıdır. M ise aralık boyutudur.
<h2>Sezar Şifreleme</h2>
<pre>P : abcd</pre>
<pre>C : bcda</pre>
<pre>K : 1</pre>
Karakterleri alfabede K sonraki harfe kaydırarak şifrelemedir.
<pre>Cn = (Pn+K)mod(HarfSayısı)</pre>
<ul>
	<li>Harfleri frekansı(sıklığı) ölçülerek kolayca çözülebilir. <span style="text-decoration: underline;">Ö</span> : Türkçede en fazla <strong>A</strong> harfi kullanılır. İngilizcede ise <strong>E</strong> harfi kullanılır. Bu bilgi dilin son yayılanan makalelerindeki harfler sayılarak elde edilebilir. Metin ne kadar uzunsa , bu yöntemle çözülmesi o kadar kolaydır.</li>
	<li>Kaba Kuvvet ile Harf Sayısı kadar şifre olasılığı (ö : 29) deneyerekte çözülebilir.</li>
</ul>
&nbsp;