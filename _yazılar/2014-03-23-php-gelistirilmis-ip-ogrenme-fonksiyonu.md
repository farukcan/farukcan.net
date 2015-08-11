---
ID: 29
post_title: >
  php Geliştirilmiş IP Öğrenme
  Fonksiyonu
author: farukcan
post_date: 2014-03-23 22:39:51
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/php/2014/03/php-gelistirilmis-ip-ogrenme-fonksiyonu/
published: true
---
<a href="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png"><img src="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png" alt="PHP_Logo" width="722" height="350" class="alignnone size-full wp-image-222" /></a>

Bu Fonksiyon ile phpde ipleri daha doğru bir şekilde elde edebilirsiniz.

<pre lang="php">function GetIP(){
    if(getenv("HTTP_CLIENT_IP")) {
         $ip = getenv("HTTP_CLIENT_IP");
     } elseif(getenv("HTTP_X_FORWARDED_FOR")) {
         $ip = getenv("HTTP_X_FORWARDED_FOR");
         if (strstr($ip, ',')) {
             $tmp = explode (',', $ip);
             $ip = trim($tmp[0]);
         }
     } else {
     $ip = getenv("REMOTE_ADDR");
     }
    return $ip;
}</pre>