---
ID: 294
post_title: Memcache injection
author: farukcan
post_date: 2015-08-16 12:11:59
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/guvenlikhack/2015/08/memcache-injection/
published: true
---
<pre>"SET deger " . $input</pre>
şeklinde bir kullanımda $input değerine <strong>\r\n </strong>karakterleri dahil edildiğinde 2. bir komut daha girilebilmektedir.
<pre>$input = "1 \r\n SET admin_password 12345";</pre>
şeklinde bir komut ile diğer memcache değerleri değiştirilebilir.

<strong>Çözüm</strong> : Alt satıra geçişe engel olmak.