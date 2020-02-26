---
ID: 20
post_title: Brute Force Algoritması
author: farukcan
post_date: 2014-03-07 20:54:51
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/algoritmalar/2014/03/brute-force-algoritmasi/
published: true
dsq_thread_id:
  - "4021112586"
---
<a href="http://farukcan.net/wp-content/uploads/2014/03/term-bruteforce.png"><img src="http://farukcan.net/wp-content/uploads/2014/03/term-bruteforce.png" alt="term-bruteforce" width="500" height="375" class="alignnone size-full wp-image-226" /></a>

<p>
	Brute force , hack saldırılarında kullanınılan, şifreyi b&uuml;t&uuml;n olasıkları deneyerek kırmaya yarayan bir algoritmadı.<br />
	Algoritmanın kapa-taslak işleyişi aşagıdadır
</p>

<pre lang="vb" line="1">#include <GUIConstantsEx.au3>

Local $haneler = StringSplit("0 1 2 3 4 5 6 7 8 9 q w e r t y u ı o p ğ ü i ş l k j h g f d s a z x c v b n m ö ç Q W E R T Y U I O P Ğ Ü İ Ş L K J H G F D S A Z X C V B N M Ö Ç",' ') ;
Local $hanesay=0;
Local $sira=1;
Local $maxhane=5
Local $bitis=1

Local $gonderi= ''
Local $logsira; o anki sayinin hac haneli olacagidir
Local $kalan=0
Local $bolum;
For $i = 1 to $haneler[0] ; kaç karakterimiz oldugu ogren
    $hanesay=$hanesay+1
 Next
For $m = 1 to $maxhane ;
	  $bitis=$bitis*$hanesay
Next
MsgBox(0,0,$hanesay & "hane var. 5 sn sonra saldiracagim $sira yi değiştirmeyi unutmayın. Olası Deneme : " & $bitis)
Sleep(5000)

;bur da  hane sayısına bölerek işlem yaptıracağız.
while $sira < $bitis
   $logsira = Floor(Log($sira) / Log($hanesay)) + 1
   $bolum=$sira
   $gonderi=''
   ; kac haneli oldugu bulduk simdi hanesayisina bolarak onu olusturalim
   if ($sira>$hanesay) Then
	  for $m = 1 to ($logsira-1)
		 $kalan=Mod($bolum,Floor($bolum/$hanesay)*$hanesay)
		 $bolum=Floor($bolum/$hanesay)
		 $gonderi= $haneler[($kalan+1)] & $gonderi
	  Next
	  $gonderi= $haneler[$bolum] & $gonderi ; en büyük basamağı sona kalır
   Else ;1 haneliyse
	  $gonderi= $haneler[$bolum] & $gonderi
   EndIf
   dene($gonderi,$sira)
   $sira=$sira+1
wend ; while sonu







Func dene($tus,$sira)
   Send($tus)
   Send("{ENTER}")

  ; ClipPut("SON DENEME SIRASI : " & $sira)

EndFunc
;~ Local $iMod1 = Mod(4, 2) ; 4%7 = 4 because the divisor > dividend6
;~ Local $iLog2 = Log(1000) / Log(74)</pre>
