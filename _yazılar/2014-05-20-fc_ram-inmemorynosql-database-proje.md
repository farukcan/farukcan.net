---
ID: 57
post_title: fc_ram inMemory/NoSQL Database (PROJE)
author: farukcan
post_date: 2014-05-20 14:51:43
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/php/2014/05/fc_ram-inmemorynosql-database-proje/
published: true
---
<center><p ><a style="color: #ff4b33; line-height: 24px;" href="http://farukcan.net/wp-content/uploads/2014/05/fc_ram.png"><img class="alignnone size-full wp-image-39" alt="fc_ram" src="http://farukcan.net/wp-content/uploads/2014/05/fc_ram.png" width="187" height="176" /></a>  </center>
<br> 	<ul>
<li>Hızlı</li>
	<li>php ile kodlanmış</li>
	<li>php ile sorgu yapan</li>
	<li>ramda depolan</li>
	<li>http:80/internet bağlantısı yapabilen her program dilini destekleyen</li>
	<li>Açık Kaynak Kodlu ve Ücretsiz</li>
	<li>PHPde veri işlemede MySQLe göre enaz 4-5 kat performans sağlayan</li>
veritabanıdır.
</ul>
</p>
PHP de kullanım örneği;
<pre lang="php" line="1">
<?php 
require_once "hata_yonetimi.php"; //fc_ram için gerekli fonksiyonlar
require_once "fc_ram.php"; //php de kullanacaksanız dahil etmeniz gereken kütüphane
$ram=new fc_ram(1,64000); // (VT_NO,VT_BOYUT-byte)
$ram->yaz('değişkeninVTdekiadı' , $phpdegiskeni );
$alınanphpdeğişken = $ram->oku('ramdaki dökümandegisken adı');
var_dump($ram->oku('ramdaki dökümandegisken adı'));
?></pre>
<a href="http://farukcan.net/wp-content/uploads/2014/05/sema.png"><img alt="sema" src="http://farukcan.net/wp-content/uploads/2014/05/sema.png"  /></a>
<h1>fc_ram için phpWebGUI arayüzü</h1>
<img style="line-height: 18px; font-size: 12px;" alt="fcramornek" src="http://farukcan.net/wp-content/uploads/2014/05/fcramornek.png" />
<img src="http://farukcan.net/wp-content/uploads/2014/05/kıyaslama.png" />
<img src="http://farukcan.net/wp-content/uploads/2014/05/veriyap.png" />
<h1>fc_ram hakkında Dökümanlar</h1>
<h2>Yapı</h2>
Ana Kontrolcu -> veri tabanlarını kontrol eder<br>
Veri tabanı -> Veri tabanları ad verilmez. No verilir. (1den65555e kadar) içinde DeğişkenDökümanlarını ve onların adını <br>saklar<br>
DeğişkenDökümanı -> 2 türlü olabilir. <br>
1. JSON Şekline getirmiş php değişkeni saklar <br>
2. si salt yazı/string saklar<br>
<br>
<h2>Sorgu sistemi:</h2>
sorgu sisteminde , sorgulama PHP dilinde yapılır.Buda büyük özgürlükler sağlar. NOT: her satırdan sonra \";\" kullanın<br>
eğer fc_ram php kodlarınınız arada kullanıyorsunuz. classı kopyala/yapıştır yapıp kullanabilrsiniz.<br>
eğer phpWebGui veya dışardan erişiyorsanınız. sorgu.php \'ye GET veya POST ile \'apiparola\' ve \'komut\' değerlerini <br>göndermeniz gerekir. parola doğruysa sorgu.php sorgunuzu işleyip geri döndürür.<br>
<br>
Veri Tabanı Oluşturma :: $ram o an oluşturulan veritabanının seçim değişkenidir. Farklı isim verebilirsiniz<br>
<pre lang="php" line="1"> $ram=new fc_ram(VT_NO,VT_BOYUT);</pre><br>
<br>
Veri tabanını seçme $ram o an oluşturulan veritabanının seçim değişkenidir. Farklı isim verebilirsiniz<br>
<pre lang="php" line="1"> $ram=new fc_ram(VT_NO);</pre><br>
<br>
Veri tabanından php değişkeni alma/okuma SELECT<br>
<pre lang="php" line="1"> $alınanphpdeğişken = $ram->oku('ramdaki dökümandegisken adı');</pre><br>
<br>
Veri tabanından yazı/string alma/okuma SELECT<br>
<pre lang="php" line="1"> echo $ram->okudata('ramdaki dökümandegisken adı');</pre><br>
<pre lang="php" line="1"> $phpstring = okudata('ramdaki dökümandegisken adı');</pre><br>
<br>
Veri tabanıda php değişkeni ekleme/oluşturma INSERT INTO ve UPDATE<br>
<pre lang="php" line="1"> $ram->yaz('değişkeninVTdekiadı' , $phpdegiskeni );</pre><br>
<br>
Veri tabanıda php değişkenini değiştirme INSERT INTO ve UPDATE<br>
<pre lang="php" line="1"> $ram->yaz('değişkeninVTdekiadı' , $phpdegiskeni );</pre><br>
<br>
Veri tabanıda php değişkenini silme DELETE <br>
<pre lang="php" line="1"> $ram->yaz('değişkeninVTdekiadı' , NULL );</pre><br>
<br>
Veri tabanına yazı/string eklme/gönderme/oluşturma INSERT INTO ve UPDATE<br>
<pre lang="php" line="1"> $ram->yazdata('değişkeninVTdekiadı' , "YAZIMIZZZZZZZZZZZ" );</pre><br>
<pre lang="php" line="1"> $ram->yazdata('değişkeninVTdekiadı\' , $phpstring );</pre><br>
<br>
Veri tabanında ki yazı/string değiştirme INSERT INTO ve UPDATE<br>
<pre lang="php" line="1"> $ram->yazdata('değişkeninVTdekiadı\' , "YAZIMIZZZZZZZZZZZ\" );</pre><br>
<pre lang="php" line="1"> $ram->yazdata('değişkeninVTdekiadı' , $phpstring );</pre><br>
<br>
Veri tabanında ki yazı/string i silme DELETE<br>
<pre lang="php" line="1"> $ram->yazdata('değişkeninVTdekiadı' , NULL );</pre><br>
<br>
<br>
eğer $php değişkeninden 2 boyutlu array (yani tablo) alıyorsanınız. sql deki ORDER BY, WHERE veya LIMIT<br>
fonksiyonlarını karşılamak için. PHPde foreach , sort , unset fonksiyonlarını öğrenmeniz gerekir. (bknz. <br>http://www.php.net)<br>
<br>
sorgulan şeyi almak için<br>
<pre lang="php" line="1"> echo $phpstring;</pre><br>
<pre lang="php" line="1"> echo $ram->okudata('ramdaki dökümandegisken adı');</pre><br>
<pre lang="php" line="1"> var_dump($phpdeğişkeni);</pre><br>
<pre lang="php" line="1"> var_dump($ram->oku('ramdaki dökümandegisken adı'));</pre><br>
<br>
<h2>fonksiyonlar:</h2>
$ram->yaz : bir php değişkenini türü ne olursa olsun JSON şekline çevirip ramde saklar<br>
$ram->yazdata : bir yazıyı veya dökümanı ek işlem yapmadan RAMe yazar<br>
$ram->oku : veritabanındaki JSON şekline çevrilmiş php değişkenini geri getirir<br>
$ram->okudata : bir yazıyı / dökümanı veya JSON şeklindeki php değişkeni json olarak okur<br>
$ram->kapat : değişken arrayındaki son değişiklikleri ram kaydeder. <br>
$ram->log : ram bilgi kaydı ekler<br>
$ram->vt_kontrolcu: ramda veritabanı yoksa yeni birtane oluşturur ve bu ram boşalana kadar devam eder. oluştururken <br>yukle fonksiyonunu çalıştırır.<br>
$ram->yukle: oclass verride idilerek kullanılır. veritabanı ilk oluşturuldugunda yapılacak şeylerdir<br>
<br>
# fc_RAM classı hakkında<br>
#  fc_RAM class by Ö. Faruk CAN<br>
#  Bu bir in-memory database\'dir. PHPde çalışır. MongoDB den ilham alınarak tasarlanmıştır. Veritabanı ve <br>DeğişkenDökümanı sistemi vardır.<br>
#  Bu Kütüphane verileri RAMde sürekli şekilde saklama yeteneğine sahip bir veritabanı görevi görür<br>
#  Veriler JSON halinde RAMde saklanır<br>
#  Veri performansı arttırır. Sık kullanılanın verilerde kullanmanız tavsiye edilir :)<br>
#  (Windows.PHP 5.3 üzerinde) Yaklaşık 0.006 sn de işlem görür. localhost üzerine kurulu MySQLden yaklaşık 4 kat daha <br>hızlıdır.<br>
# - Gereksinimler:<br>
#  	*php_shmod eklentisi gerektirir ki bu birçok sunucuda kurulu halde gelir :)<br>
#  	*xdie() fonksiyonu gerektirir.Bu hataları yönetime bildirmek içindir. yoksa die() kullanabilirsin. fonksiyon <br>için farukcan.net<br>
# - Kullanımım:<br>
# Bu veritabanında veritabanlarına ad verilmez, numara verilir. Bir veritabanı söyle seçilir:
# 	* $ram=new fc_Ram([veritabanı nosu : 1],[veritabanı boyutu : 32000*byte*]); // [SEÇİME BAĞLI] veritabanı nosu 1 <br>den 66555e kadar desteklenir. <br>
#	* $ram->yaz(\'dökümandeğişkeniadı\' , $phpdegiskeni); // phpdeki her türlü arrayı class saklayabilirsiniz. mysql <br>de altığının 2 boyutlu arrayları bile.<br>
#	* $phpdegiskeni = $ram->oku(\'dökümandeğişkeniadı\'); //değişkeni önceden gönderdiğiniz gibi alırsınız.<br>
# NOT : -WHERE- & -ORDER BY- komutları nerde diyorsanır. PHPnin sort ve array fonksiyonları göz atın.<br>
# NOT : Vt boyutu maximum kapasitesine ulaştığı zaman hata verir ve sıfırlanır. Lütfen Max Boyutu ona göre ayarlatın.<br>
# NOT : Classlara RAMdan değerlerini atamak için classı  extends ramdanyuklebilir yapmanız gerekir. ramdanyuklebilir <br>classı için farukcan.net<br>

<a href="http://pc.cd/U5J"> <h1>İNDİR : Son Sürüm v1.1</h1> </a>
<h3>Dosyalar</h3>
<ol>
	<li>api_parola.php</li>

	<li>fc_ram.php</li>

	<li>fc_ram_gui.php</li>

		<li>sorgu.php</li>

	<li>hata_yonetimi.php</li>


	<li>BENiOKU.txt</li>

	<li>fc_ram.png</li>

	<li>icon.png</li>

	<li>LiSANS.txt</li>

	<li>sema.png</li>

	<li>stil.css</li>

</ol>
<h3>Önceki Sürümler</h3>
http://pc.cd/gXm
<h3>KURULUM</h3>
Dosyaları php sunucusu klasörüne çıkartın.<br>
API Şifresi, hem k.adı hem şifre görevi görür.<br>
Onları kontrol etmek için api_parola.php dosyasına göz atın.<br>
phpWebGUI için<br>
http://siteveyalocalhost/fc_ram/fc_ram_gui.php
