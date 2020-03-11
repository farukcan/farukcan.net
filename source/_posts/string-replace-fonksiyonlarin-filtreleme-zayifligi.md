---
ID: 241
title: >
  string replace fonksiyonların
  filtreleme zayıflığı
author:
  - farukcan
date:
  - 2015-08-12 10:27:08
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
  - "4025014373"
---

Bir çok programlama dilinde var olan, String Replace fonksiyonları, bir kelimenin kullanmasını engellemede çözüm yolu olduğu düşünülse bile bu fonksiyonun bir zayıflığı vardır.

&nbsp;

herhangi bir dilde stringi replace etmeyi deneyelim. (ö: php)
<pre>$id = str_replace('union', '', strtolower($_GET['id']));</pre>
Bu fonksiyon dışardan aldığı bütün union kelimeleri yok edecektir.
<pre>"union-union"  : "-"</pre>
fakat biz yinede union kelimesi gönderebiliriz.

un<span style="color: #ff0000"><strong>union</strong></span>ion şeklindeki bir kullanımda fonksiyon, unionu yok edip yerine yine union bırakacaktır.
<pre>"ununionion" : "union"</pre>
&nbsp;

Bu zayıflığı kapatmak için algoritma
<pre>while(kelime.deVarMı(silinecek)){
kelime = kelime.replace(silinecek,"");
}</pre>
