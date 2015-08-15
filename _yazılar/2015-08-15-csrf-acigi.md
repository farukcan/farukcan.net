---
ID: 283
post_title: CSRF Açığı
author: farukcan
post_date: 2015-08-15 20:07:21
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/genel/2015/08/csrf-acigi/
published: true
---
<strong>CSRF</strong> : Cross Site Request Forgory

Siteler arası istek gönderebilme açığıdır.

A sitesinde, /paroladeğiş?yeniparola=xxx diğer bir istek ile şifre değiştirildiğini fark edelim.

B sitesinde &lt;img src="A/paroladeğiş?yeniparalo=12345"/&gt; şeklinde bir kullanımla, A sitesindeki kullacının parolasını değiştirebiliriz.