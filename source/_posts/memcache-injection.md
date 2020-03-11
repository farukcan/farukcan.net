---
ID: 294
title: Memcache injection
author:
  - farukcan
date:
  - 2015-08-16 12:11:59
post_excerpt:
  - ""
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - sibergüvenlik
dsq_thread_id:
  - "4037498447"
---

<pre>"SET deger " . $input</pre>
şeklinde bir kullanımda $input değerine <strong>rn </strong>karakterleri dahil edildiğinde 2. bir komut daha girilebilmektedir.
<pre>$input = "1 rn SET admin_password 12345";</pre>
şeklinde bir komut ile diğer memcache değerleri değiştirilebilir.

<strong>Çözüm</strong> : Alt satıra geçişe engel olmak.
