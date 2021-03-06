---
ID: 252
title: Kriptoloji
author:
  - farukcan
date:
  - 2015-08-12 12:20:59
post_excerpt:
  - ""
layout: post
published: true
category:
  - Yazılım
tags:
  - sibergüvenlik
  - yazılım
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
Son kısma dikkat ; <em>P xor K xor K = P </em>oluyor. Yani XOR ile şifrelemede Key iki defa kullanılamaz.
<pre>P1 xor K = C1</pre>
<pre>P2 xor K = C2</pre>
olsun.  O zaman
<pre>C1 xor C2 = P1 xor P2</pre>
Yani Şifrelenmiş iki metni'nin xor, Şifrelenmemiş hallerinin iç içe geçmiş hali olacaktır. Eğer bunu bir resimde yapsaydık, iki resmi içi içe görürdük.
<h3>OTP (Vernam)</h3>
<strong>One-time pad</strong> (Tek kullanımlık Şerit): P xor K = C 'nin tektek her bit için kullanıldığı. P ve K şeritlerini alıp C şeridi veren şifreleme türüdür. Sadece bir defa kullanılmalıdır. Kırılmasının imkansız olduğu kanıtlanmıştır. Anahtar üretme ve dağıtma zorluğu vardır.
<h2>Rastgelelilik</h2>
Rastgelelilik bir teoridir. Birşeyin rastgele olmasının sebebi, onu hesaplayamamız veya nasıl hesaplanacağını bilmemizdir.

<strong>Pseudo Random Number Generator : </strong>

Bu algoritma mod fonksiyonun geri döndürülemezlik özelliğini kullanır.
<pre><strong></strong>Xi+1 = (a.Xi+c)modM;</pre>
Bu C'dilin random sayı üretme algoritmasıdır. a ve c sabit değerdir. (asal sayı olması önerilir) Xi önceki random üretilen sayıdır. M ise aralık boyutudur.
<h2>Sezar Şifreleme</h2>
@monoalphabetic chiper family
<pre>P : abcd</pre>
<pre>C : bcda</pre>
<pre>K : 1</pre>
Karakterleri alfabede K sonraki harfe kaydırarak şifrelemedir.
<pre>Cn = (Pn+K)mod(HarfSayısı)</pre>
<ul>
	<li>Harfleri frekansı(sıklığı) ölçülerek kolayca çözülebilir. <span style="text-decoration: underline">Ö</span> : Türkçede en fazla <strong>A</strong> harfi kullanılır. İngilizcede ise <strong>E</strong> harfi kullanılır. Bu bilgi dilin son yayılanan makalelerindeki harfler sayılarak elde edilebilir. Metin ne kadar uzunsa , bu yöntemle çözülmesi o kadar kolaydır.</li>
	<li>Kaba Kuvvet ile Harf Sayısı kadar şifre olasılığı (ö : 29) deneyerekte çözülebilir.</li>
</ul>
<h1>Simetrik Şifreleme</h1>
Tek bir anahtar ile , hem şifreleme hemde deşifreleme işlemi yapmaktır.
<h2>DES (Veri şifreleme standartı)</h2>
Herkesin bilebildiği, şifrenin gizliliğine dayalı , IBM tarafından üretilenen bir standart simetrik algoritmadır.  Key 56 bit sabittir.
<ul>
	<li>Permutasyon fonksiyonu ile yer değiştirme yapılır. Bu yüzden metinden bir bit bile değişirse, şifreli metnin neredeyse tamamı değişir.</li>
	<li>Metin ikiye bölünür.(sol,sağ) Keyden subkeyler üretilir. Sağ taraf, subkey ile F fonksiyonuna yönlendirilir. F fonksiyonu, sol taraf ile xor'lanır. Sonraki aşamada XOR'lanmış değer sağ taraf, F fonksiyonun sol taraf olur. Bu işlem 16 defa yapılır.</li>
	<li>Rivayet: Artık kullanımı iptal edilmiştir. Güvensizdir. Çünkü : Deşifrelemede, key'e bir bit yaklaşılırsa. Metinin yarısı çözülür.</li>
	<li>99da 22 saat 15 dakikada kırılabilmiştir. (Metin : Romada görüşürüz. Herkes AES kullansın.)</li>
	<li>DES'in açığı bilerek bırakılmamıştır. O dönemde güçlü olduğu düşünülüyordu. (1977)</li>
</ul>
<h2>AES (Gelişmiş şifreleme standartı)</h2>
Joan Daemen ve Vincent Rijmen adlı 2 belçikalı bulmuştur. Romadaki AES yarışmasında birinci olmuştur. (15 algoritmadan) Asıl adı : RIJNDAE
<ul>
	<li>AES, 2000 yılında çıktı. Keyler 128,196 ve 256 bittir. Blok boyutu 128 bittir.</li>
</ul>
<h2>RC4</h2>
40-2048 bit key sahibi, 256 roundlik bir şifreleme biçimidir.
<h1>Asimetrik Şifreleme</h1>
Şifrelemek için ayrı şifre, şifrelemiş metini çözmek için ayrı şifre gerek şifreleme biçimidir.
<h2>RSA</h2>
Asal sayıların kullanıldığı asimetrik şifreleme algoritmasıdır.
<h2>CBC modu</h2>
<strong>iv</strong> (initialization vector) : başlangıç vektörü. şifreleme algoritması için gerekli olan başlangıç bilgisidir.(gizlenmelidir) 0. bloktan sonrakiler için gerekmemekte.
<h2>CFB modu</h2>
Kendini feedbackleyen moddur.
<h2></h2>
<h1>Hash</h1>
Veriyi özetlemek, doğruluğunu kontrol etmek için kullanılan fonksiyondur. Geri döndürülemez olmamalıdır. Adli işlerde , kanıtların doğruluğunu ve değiştirilmedini kanıtlamak için kullanılır. Hep sabit uzunlukla çıktı verir.
<h2>md5</h2>
popüler ve hızlı hash algoritmasıdır. Sözlük saldırısı ile geri döndürebilme ihtimalı vardır. md5("dsadas".text) ile tuzlama yapılarak bundan korunulabilmektedir.
