---
ID: 283
title: CSRF Açığı
author:
  - farukcan
date:
  - 2015-08-15 20:07:21
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
  - "4036997640"
---

<strong>CSRF</strong> : Cross Site Request Forgory

Siteler arası istek gönderebilme açığıdır.

A sitesinde, /paroladeğiş?yeniparola=xxx diğer bir istek ile şifre değiştirildiğini fark edelim.

B sitesinde &lt;img src="A/paroladeğiş?yeniparola=12345"/&gt; şeklinde bir kullanımla, A sitesindeki kullanıcının parolasını değiştirebiliriz.

Dikkat edelim ki, A sitesinde kullanıcı oturum açmış olmalıdır. Bu işlem B'ye giren her ayrı kullanıcı için gerçtir.

Ancak isteklerin GET metodu dahilinde de olması gerekmez. Bir Ajax formu ile B sitesi, POST metodu da kullanılabilir.
<h3>Çözüm Yolu</h3>
Access-Control-Allow-Origin headeri kesinlikle gönderilmemelidir. Modern tarayıcılar bu headeri gördüğü müddetçe güvenliği sağlarlar. Ardından aşağıdaki iki yöntemden birini kullanmalısınız.
<h4>CSRF - Token</h4>
Form gönderilmeden önce rastgele bilet oluşturulur. Formun alıcı sayfası, bu biletin aynısını bekleyerek çalışır
<h4><b>Captcha</b></h4>
Form ve Form alıcı sayfaya bir captcha sistemi kurulur.
