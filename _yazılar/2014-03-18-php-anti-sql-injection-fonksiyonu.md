---
ID: 24
post_title: php Anti SQL Injection Fonksiyonu
author: farukcan
post_date: 2014-03-18 14:56:15
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/guvenlikhack/2014/03/php-anti-sql-injection-fonksiyonu/
published: true
---
<a href="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png"><img src="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png" alt="PHP_Logo" width="722" height="350" class="alignnone size-full wp-image-222" /></a>

Bu php fonksiyonu ile GET/POST metodları kullanılarak yapılabilecek bütün <strong>sql injection  </strong>saldırılarını engelleyebilirsiniz.
<pre lang="php" line="1">
function antisqlinjection(){
global $_POST,$_GET;
// ## Anti SQL injection . farukcan.net ÖMER FARUK CAN ##
// NOT : sadece POST ve GET ten gelen sql saldırılarına karşı koyar. sesion ve cookilere dikkat edin
$degson="";
$ara  = array('\n', '\r', '\n\r', 'antisqlinjection'); //değişecek şeyler
$degis = array('', '', '', 'antisqlinjectionV1farukcan.net');
    if ($_POST)
        foreach ($_POST as $ad => $deg)
        {
            $degson=str_replace($ara, $degis, $deg);
            $_POST["$ad"]=addslashes($degson); // slash ekle
        }
    if ($_GET)
        foreach ($_GET as $ad => $deg)
        {
            $degson=str_replace($ara, $degis, $deg);
            $_GET["$ad"]=addslashes($degson);
        }
}

## KULLANIMI :: php sayfasını başına eklenir
antisqlinjection();
</pre>