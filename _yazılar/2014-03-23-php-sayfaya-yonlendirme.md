---
ID: 33
post_title: php Sayfaya yönlendirme
author: farukcan
post_date: 2014-03-23 22:42:08
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/php/2014/03/php-sayfaya-yonlendirme/
published: true
dsq_thread_id:
  - "4040024327"
---
<a href="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png"><img src="http://farukcan.net/wp-content/uploads/2014/03/PHP_Logo.png" alt="PHP_Logo" width="722" height="350" class="alignnone size-full wp-image-222" /></a>

Bu fonksiyon ile daha etkin/stabil bir şekilde kullanıcıları başka bir sayfaya yönlendirebilirsiniz.

<pre lang='php'>
function yonlendir($url){
    if (!headers_sent()){  
        header('Location: '.$url); exit; 
    }else{ 
        $sayfaKod.= '<script type="text/javascript">'; 
        $sayfaKod.= 'window.location.href="'.$url.'";'; 
        $sayfaKod.= '</script>'; 
        $sayfaKod.= '<noscript>'; 
        $sayfaKod.= '<meta http-equiv="refresh" content="0;url='.$url.'" />'; 
        $sayfaKod.= '</noscript>'; exit; 
    }
}
</pre>