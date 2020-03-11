---
ID: 205
title: Asal sayı doğrulama
date: 2015-10-11 19:34:4
author:
  - farukcan
post_excerpt:
  - ''
layout: post
category:
  - Yazılım
tags:
  - asal
  - matematik
  - javascript
  - yazılım
published: true
dsq_thread_id:
  - '4022869366'
---
<a href="/html/uploads/2015/05/prime-numbers-02.jpg"><img src="/html/uploads/2015/05/prime-numbers-02.jpg" alt="prime-numbers-02" width="446" height="250" class="alignnone size-full wp-image-208" /></a>Bir sayının asallığını en hızlı şekilde doğrulayan fonksiyondur

{% codeblock lang:js %}
  function isPrime(n) {
   if (isNaN(n) || !isFinite(n) || n%1 || n&lt;2) return false;
   if (n%2==0) return (n==2);
   if (n%3==0) return (n==3);
   var m=Math.sqrt(n);
   for (var i=5;i&lt;=m;i+=6) {
    if (n%i==0)     return false;
    if (n%(i+2)==0) return false;
   }
   return true;
  }
{% endcodeblock %}
