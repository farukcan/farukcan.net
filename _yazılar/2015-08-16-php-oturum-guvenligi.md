---
ID: 289
post_title: PHP Oturum Güvenliği
author:
  - farukcan
post_date:
  - 2015-08-16 11:25:58
post_excerpt:
  - ""
layout: post
permalink:
  - ""
published: true
dsq_thread_id:
  - "4054801562"
---

<h3>Session</h3>
Sunucu tarafında tutulan , oturum bilgileri (PHPde PHPSSID diye cookie tutulur.)
<h3>Cookie</h3>
Browser tarafında tutulan oturum bilgileri

<span style="color: #ff0000">PHP phpssid 'de ağ dinlenerek elde edilebilir. Başkasının phpssid'ine sahip olduğunuz an onun oturumunu elde edersiniz.</span>
<h2>Çözüm Yolları</h2>
<ul>
	<li>session_regenerate_id fonksiyonu ile her seferinde phpssid'i yenileyin.</li>
	<li>isteğin geldiği ip adresini kontrol et ve doğrula.</li>
	<li>bir oturum aynı anda sadece bir yerde açık olabilsin. (yeniden üretilen ssid , yeniden giriş olma durumda, tekrar yenilenir.)</li>
</ul>