---
ID: 205
post_title: Asal sayı doğrulama
author: farukcan
post_date: 2015-05-28 11:38:56
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/algoritmalar/2015/05/asal-sayi-dogrulama/
published: true
dsq_thread_id:
  - "4022869366"
---
<a href="http://farukcan.net/wp-content/uploads/2015/05/prime-numbers-02.jpg"><img src="http://farukcan.net/wp-content/uploads/2015/05/prime-numbers-02.jpg" alt="prime-numbers-02" width="446" height="250" class="alignnone size-full wp-image-208" /></a>Bir sayının asallığını en hızlı şekilde doğrulayan fonksiyondur

<pre lang="javascript">
  function isPrime(n) {
   if (isNaN(n) || !isFinite(n) || n%1 || n<2) return false; 
   if (n%2==0) return (n==2);
   if (n%3==0) return (n==3);
   var m=Math.sqrt(n);
   for (var i=5;i<=m;i+=6) {
    if (n%i==0)     return false;
    if (n%(i+2)==0) return false;
   }
   return true;
  }


</pre>