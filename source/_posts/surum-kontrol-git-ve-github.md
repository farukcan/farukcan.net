---
ID: 594
title: 'Sürüm Kontrol : Git ve Github'
author: farukcan
date: 2017-04-07 17:47:41
post_excerpt: ""
layout: post
published: true
category:
  - Yazılım
tags:
  - git
  - github
  - repository
  - commit
dsq_thread_id:
  - "5836712388"
---
Yazılım projesi geliştirirken, kademeli olarak kodları yedeklemek ve saklamak gerekmektedir. Bu yedeklemeler yapılırken gerektiğinde önceki sürüme geri dönebilmemiz ve önceki sürüm ile farkları (change log) belirlememiz gerekmektedir.

Bunun yanı sıra, bir projede birden çok yazılımcı çalıştığı için, yapılan değişikliklerin birbiriyle çakışmaması gerekmektedir. Sürüm kontrol sistemlerinin yaptığı şey de budur.

Şu an en yaygın versiyon kontrol sistemi "<strong>Git</strong>"dir. Bu yazılım aynı zamanda Linuxun da geliştiricisi olan Linus Torvalds tarafından geliştirilmiştir. Açık kaynak kodlu, ücretsiz bir yazılımdır.

"<strong>Github</strong>" ise kodların saklanıldığı uzak sunucu (remote) git servisidir.

<strong>Repository</strong> : git projelerinin her birine verilen addır.

<strong>Commit</strong> : Herbir sürüme verilen isimdir. Her değişiklik yapılan adımdır. Hash Key , Ad ve açıklama içerir.

<strong>Branch</strong> : Değişliğin yapıldığı branşa verilen isimdir. Her repositoryinin ana branşı masterdır. Yani uygulamanın asıl sürümünü master branch oluşturur.
<pre>git clone &lt;adres&gt;
- uzak sunucudaki kodları geliştiricinin bilgisayarına klonlar

git commit -am &lt;mesaj&gt;
- Kodda yapılan değişikliklerden commit oluşturur

git push
- Commitleri uzak sunucuya gönderir

git pull
- Uzak sunucudaki commitleri ve güncellemeleri alır.

git init
- Herhangi bir klasörde git repositorysi oluşturur.</pre>
