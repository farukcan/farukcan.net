---
ID: 241
post_title: >
  string replace fonksiyonların
  filtreleme zayıflığı
author: farukcan
post_date: 2015-08-12 10:27:08
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/guvenlikhack/2015/08/string-replace-fonksiyonlarin-filtreleme-zayifligi/
published: true
dsq_needs_sync:
  - "1"
---
Bir çok programlama dilinde var olan, String Replace fonksiyonları, bir kelimenin kullanmasını engellemede çözüm yolu olduğu düşünülse bir bu fonksiyonun bir zayıflığı vardır.

&nbsp;

herhangi bir dilde stringi replace etmeyi deneyelim
<pre>$id = str_replace('union', '', strtolower($_GET['id']));</pre>
Bu fonksiyon dışardan aldığı bütün union kelimeleri yok edecektir.
<pre>"union-union"  : "-"</pre>
fakat bir yinede union kelimesi gönderebiliriz.

un<span style="color: #ff0000;"><strong>union</strong></span>ion şeklindeki bir kullanımda fonksiyon, unionu yok edip yerine yine union bırakacaktır.
<pre>"ununionion" : "union"</pre>
&nbsp;