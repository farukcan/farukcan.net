---
title: Bir GitHub Repositorysini CDN olarak kullanmak
author: farukcan
date: 2020-06-16 13:05:22
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - git
  - github
  - cdn
  - gömülü
  - jsdelivr
---

# jsDelivy

Bugün bir GitHub repositorysindeki dosyaları CDN (Content Delivery Network) olarak kullanmanın yolunu keşfettim.
Bu sayede resimleri github üzerine upload edip, CDN ile daha hızlı ve optimize
şekilde yüklenmesini sağlayabiliyoruz.

Tabi bu sadece resimler için geçerli bir yöntem değil, aynı şekilde kendi kütüphanelerinizi ve kodlarınıza da
bu şekilde, dünyanın her yerinden hızlı erişime sunabilirsiniz.

Siteniz zaten GitHub Pages üzerinde bulunuyorsa bile sitenize erişimde (arada CloudFlare gibi proxyler 
kullanıyorsanız ) bir yavaşlık oluşacaktır. Kendi GitHub Pages sayfanızada da resimler, javasscript kodları için 
bir CDN ile erişmek süreci hızlandıracaktır.

## Avantajları

* Hızlı erişim 
* Dünyaya geneline yayılmış bir ağdan dosya alarak gecikmelerin azaltılması
* Kalıcılık (Dosyalar public bir repositoryde güvenli olarak saklanacak)
* Websitelerini veya webe bağlı uygulamaları hızlandırmak için birebir.

## Kullanımı

Bu şekilde GitHub reposundaki dosyanızı linkliyorsunuz. Kendisi otomatik olarak optimize ediyor.

`https://cdn.jsdelivr.net/gh/{github kullanıcı adı}/{repo kodu}/{dosyanın adresi}`

Tabi Branş ve versiyonda kullanabilirsiniz.

`https://cdn.jsdelivr.net/gh/{github kullanıcı adı}/{repo kodu}@{versiyon veya branş}/{dosyanın adresi}`

Sadece GitHub için değil, npm ve wordpress içinde kullanabilirsiniz : https://www.jsdelivr.com/?docs=gh

### Örnek

https://cdn.jsdelivr.net/gh/farukcan/farukcan.net/
(Repodaki bütün dosyaları listelemek için)

(Tek bir resme erişim örneği)
https://cdn.jsdelivr.net/gh/farukcan/farukcan.net@master/source/images/embedded/Untitled%204.png
```
// load any GitHub release, commit, or branch
// note: we recommend using npm for projects that support it

https://cdn.jsdelivr.net/gh/user/repo@version/file

// load jQuery v3.2.1

https://cdn.jsdelivr.net/gh/jquery/jquery@3.2.1/dist/jquery.min.js

// use a version range instead of a specific version

https://cdn.jsdelivr.net/gh/jquery/jquery@3.2/dist/jquery.min.js
https://cdn.jsdelivr.net/gh/jquery/jquery@3/dist/jquery.min.js

// omit the version completely to get the latest one
// you should NOT use this in production

https://cdn.jsdelivr.net/gh/jquery/jquery/dist/jquery.min.js

// add ".min" to any JS/CSS file to get a minified version
// if one doesn't exist, we'll generate it for you

https://cdn.jsdelivr.net/gh/jquery/jquery@3.2.1/src/core.min.js

// add / at the end to get a directory listing

https://cdn.jsdelivr.net/gh/jquery/jquery/

```
