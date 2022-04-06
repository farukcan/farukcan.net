---
ID: 269
title: Sosyal Mühendislik
author:
  - farukcan
date:
  - 2015-08-13 12:21:34
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
  - "4028375344"
---

Hackenen firmalar incelendiğinde, daha çok farkındanlık eksikliğinden kaynaklı olarak hacklendiği ortaya çıkmıştır.

Sosyal Mühendisliğin <em>ilk aşaması, <strong>bilgi toplamadır</strong>.</em>
Ö: Bankalarda, IT elamanı gibi gözüküp, onların emaili adreslerine ve bilgilerine erişmektir
<h3>theharvester</h3>
Bilgi toplama uygulaması.(bknz: kali linux) Sitenin emaileri, subdomainleri ve diğer virtual hostları bulabilmektedir.
<pre>theharvester -d farukcan.net -l 500 -b all</pre>
<h3>Google Hacking</h3>
Google arama motoru hedefe yönelik optimize aramalar yapabilir.
<pre>site:twitter.com
filetype:pdf
intitle:Başlıkta Var
"Beni Bir Bütün Halde Ara"
intext:Dosyanın içinde
inurl : url içinde
ömer -"faruk can" (içinde farukcan geçmeyen ömerler)
tc kimlik hack
site:*.gov.tr filetype:xlsx numrange:10000000000-99999999999

"sifre" filetype:sql</pre>
<h3>emkei.cz - Sahte mail gönderme</h3>
Bu site başkası adına email göndermeyi sağlamaktadır. Fakat spama düşme ihtimalı yüksektir. (eğer hotmail veya gmail kullanıyorsanız)

<span style="color: #ff0000">Bana gönderilen emailin gerçek olduğunu nasıl anlarım?</span>

Gelen emailin kaynak koduna bakalım.
<pre>Received: from emkei.cz ([46.167.245.116]) by natrohost.com with MailEnable ESMTP; Thu, 13 Aug 2015 11:38:45 +0300
Received: by emkei.cz (Postfix, from userid 33)
	id DD39C6F95C; Thu, 13 Aug 2015 10:33:22 +0200 (CEST)
To: omer@farukcan.net
Subject: dsadas
From: "dadsInce" &lt;d@das.net&gt;
X-Priority: 3 (Normal)
Importance: Normal
Errors-To: dsa@dsa.net
Reply-To: dsa@ads.net
Content-Type: text/plain; charset=utf-8
Message-Id: &lt;20150813083322.DD39C6F95C@emkei.cz&gt;
Date: Thu, 13 Aug 2015 10:33:22 +0200 (CEST)
Received-SPF: none (natrohost.com: dsa.net does not designate permitted sender hosts)
X-Envelope-Sender: dsa@das.net
Return-Path: &lt;das@das.net&gt;</pre>
Dikkat ederseniz. Gönderen sunucu emkei.cz'dir. Email adresi ve gönderen sunucunun farklı olma durumu bu emailin sahte olduğunu gösterir.

<span style="font-size: 17px;line-height: 1.6471">http://mxtoolbox.com/ sitesine bakıp farukcan.net ' üzerinden eposta göndermeye yetkili sunucu adreslerini görebilirsiniz.</span>
<h3>Sahte email gelen kutusu</h3>
https://mailinator.com/inbox.jsp?to=sahteemail

Bu adresinde gelen kutusuna, gizli bir adresten email gönderip. Girş yapmadan yine sahteemail@mailinator.com'un gelen kutusunu okuyabilirsiniz.
<h3>email sunucusun anti virüs varlığının tespiti</h3>
o sunucu üzerinde olmayan bir email adresine mail gönderir. Sunucu bize olmadığına dair email gönderir. Bizde bu emailin kaynağının header bilgisine bakarız. SMTP-Filter veya Antivirüs kısımlarına bakarak varlığını tespit edebiliriz.
<h2>setoolkit</h2>
Sosyal Mühendislik için bir araçtır. (kali linux)

Sayfa Kolonlama 1,2,3,2
<h4>Benzer gözüken bir domain/dns elde etme</h4>
freedns.afraid.org : Burdan www.facebook.com.blabla.dasdsad.net/index.html?dasdas&amp;dasdas tarzı anlaşılmayacak bir url oluşturabiliyorsun.
<h3>inial paypal kart</h3>
Hackerlar ,isimsiz alınan bu karta para yükleyerek, rusya ve çin gibi uzak ülkelerden sunucu kiralayıp kimliklerini gizlemektedir. (bknz: migros)

&nbsp;
<h4>Suriyeli Hackerların Başbakanlık ve içişleri emaillerini yaptığı Sosyal Mühendislik Saldırısı</h4>
Site kolonlama ile suriyeli hackerlar yüzlerce başbakanlık ve içişleri email adreslerinin şifrelerini öğrenmişlerdir.

<h4>2 aşamalı doğrulama</h4>
facebook ve google, şifrenin yanında sms doğrulama kodu isteyerek, giriş isteyebilmektedir. Bunların güvenliği çok yüksektir.
<h3>USB HID (USB Rubber ducky)</h3>
Takıldığında, bilgisayarla otomatik tuşlar gönderen klavyedir. Taktığınız zaman tuşlar ile gizli bir şekilde bilgisayara komutlara girer. Doğrudan bu yolla casus yazılım yüklenebilir. Hiç bir antivirüs bu aygıtı tanımaz. Kullanıcı oluşturabilir, casus yazılım indirip yükleyebilir. DNS ayarlarını değiştirebilir. Micro USB ile mobil cihazlara takılabilir.
<h3> fimap</h3>
sunucunun dosya erişim açığı var mı kontrol eder
