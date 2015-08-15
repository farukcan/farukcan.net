---
ID: 281
post_title: IDOR Açığı
author: farukcan
post_date: 2015-08-15 17:10:52
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/genel/2015/08/idor-acigi/
published: true
---
<strong>IDOR</strong> : insecure direct object reference.

Yazılımcının , bir sayfa üzerinden , başka kullanıcıların erişmemesi gereken bilgilere, yetki vermemeyi unutması ile oluşan açıktır.

Mesela kullanıcının, yapacaklarım listesi olsun. X'nin yapacaklarından biri <em>/yapacaklar?id=65445</em>  sayfası üzerinde olsun. Eğer A, kullanıcısı <em>/yapacaklar?id=61445</em> sayfası üzerinden B'nın verilerine erişebilmesi bu açığa örnektir.