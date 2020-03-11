---
ID: 326
title: HTML5 Local Storage
author:
  - farukcan
date:
  - 2015-08-19 11:57:10
post_excerpt:
  - ""
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - javascript
dsq_thread_id:
  - "4054799133"
---

Cookieler, max 4KB'tır ve her istekte sunucuya tekrar gönderilir. Eğer kullanıcının browserda bir şey depolamak istersek ve buna sadece javascriptten erişmek istersek Local storage kullanabiliriz.

<strong>Veri yazma</strong>
<pre>localStorage.setItem("key", "value");</pre>
<strong>Veri okuma</strong>
<pre>localStorage.getItem("key");</pre>
<strong>Veri silme</strong>
<pre>localStorage.removeItem("key");</pre>
