---
ID: 274
title: XSS Açığı
author:
  - farukcan
date:
  - 2015-08-13 17:39:48
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
  - "4037001204"
---

<strong>Payload</strong> : XSS açığını kullanan koddur.

<strong>Reflected XSS</strong> : URL'ya gidilmesi üzerine çalışan XSS'dir. Kalıcı değildir

<strong>Stored XSS</strong> : Veritabanında kalıcı olarak saklanabilen XSS payloadıdır.

Bir web sitenin &lt;script&gt; ( ) ' " işaretlerinin kullanıma izin vermesiyle oluşan açıktır.

<em>document.cookie</em> ile cookiler çalınabilmektedir. Fakat browserlar artık bunları filtreleyip gönderebilmektedir.

Flash ve Java üzerinden bilgisayar ele geçirebilmektedir. Plugin yükleterek, tarayıcı elegeçilebilir.

<strong>HTML Context</strong> : &lt;p&gt;Ahmet&lt;/p&gt;

<strong>Attribute Context</strong> : &lt;input value="Ahmet" onChange="jsfunc();"&gt;

<strong>Script Context</strong> : &lt;script&gt; var name='Ahmet';  &lt;/script&gt;

<strong>Style Context</strong> : css kodları arasını XSS enjekte etmektir.

<strong>URI Context</strong> : &lt;a href="javascript:alert(1)"&gt; ...

* XSS'te doğru sintaks oluşturma derdi yoktur.

<span style="color: inherit;font-family: Oxygen, sans-serif;font-size: 24px;font-weight: bold;line-height: 1.1667">BeEF</span>

XSS sploitidir.
<h4>GMail XSS saldırısı</h4>
<em>&lt;img src#@blla.com</em> gibi bir email mümkündür.
<h4>DropBox/FB XSS &amp; Linuxda Dosya İsimleri</h4>
Linuxda / dışında her karakter dosya isminde kullanılır. Bu sebeple böyle bir dosyayı DropBox'a yükleyip tarayıcı script çalıştırılmaktadır.

&nbsp;
