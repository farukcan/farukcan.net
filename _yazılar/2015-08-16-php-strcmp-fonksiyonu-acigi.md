---
ID: 292
post_title: PHP strcmp fonksiyonu açığı
author:
  - farukcan
post_date:
  - 2015-08-16 11:42:49
post_excerpt:
  - ""
layout: post
permalink:
  - ""
published: true
dsq_thread_id:
  - "4081620556"
---

strcmp fonksiyonu iki değer eşit olması durumunda 0 (false) döndürür
<pre>strcmp("5", 5) =&gt; 0
strcmp("15", 0xf) =&gt; 0
strcmp(61529519452809720693702583126814, 61529519452809720000000000000000) =&gt; 0
strcmp(NULL, false) =&gt; 0
strcmp(NULL, "") =&gt; 0
strcmp(NULL, 0) =&gt; -1
strcmp(false, -1) =&gt; -2
strcmp("15", NULL) =&gt; 2
strcmp(NULL, "foo") =&gt; -3
strcmp("foo", NULL) =&gt; 3
strcmp("foo", false) =&gt; 3
strcmp("foo", 0) =&gt; 1
strcmp("foo", 5) =&gt; 1
strcmp("foo", array()) =&gt; NULL + PHP Warning
strcmp("foo", new stdClass) =&gt; NULL + PHP Warning
strcmp(function(){}, "") =&gt; NULL + PHP Warning</pre>
Eğer sitenizde şöyle bir kullanım yaptıysanız.
<pre>if(!strcmp($_GET["ad"], "admin"))
 echo "hg";
else
 echo "dg";</pre>
bu admin ile kıyaslama, GET-ad değişkeni <strong>array</strong>,null,class veya fonksiyon olduğu zamanda <strong>TRUE</strong> değer döndürür ve <strong>hg</strong>(hoşgeldin) mesajı basar.

Şu şekilde bir kullanım ile get metodu üzerinde array gönderilebilirsiniz.
<pre>http://localhost/strcmp.php?ad[0]=omer</pre>
Eğer şifre ve kullanıcı adınızı bu şekilde doğruluyorsanız, birinin array göndererek admin panelinize erişmesi mümkündür.

Onun için == ile kıyaslama yapınki sistem <strong>dg</strong> (defol git) değeri döndürsün.

&nbsp;