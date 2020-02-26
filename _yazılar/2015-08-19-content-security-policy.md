---
ID: 328
post_title: Content Security Policy
author:
  - farukcan
post_date:
  - 2015-08-19 12:13:32
post_excerpt:
  - ""
layout: post
permalink:
  - ""
published: true
dsq_thread_id:
  - "4053776326"
---

<pre>connect-src : WebSocket, XHR, EventSource
font-src : https://themes.googleusercontent.com //fontları sadece ordan alabilir
frame-src: https://youtube.com //frame sadece youtube olabilir.
img-src : * -Her şeye izin ver- // self yazarsan sadece kendi resimleni alır
media-src : *.site.com // mediayi kendi domaninde izin ver
object-src : self // flash vb
script-src : ‘self’ ‘unsafe-eval’ ‘unsafe-inline’ //kendi için evala izin verme
style-src : self</pre>
Şeklinde headerda (X-WebKit-CSP) gönderilen güvenlik bilgileridir. Bunlar tarayıcı tarafından uygulanır.