---
ID: 597
post_title: Facebook Pixel
author: farukcan
post_date: 2017-04-10 13:56:03
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/yazilim-teknolojileri/2017/04/facebook-pixel/
published: true
---
Facebook üzerinde yayınlanan reklamlardan elde edilen bilgilerle dönüşüm ve retargeting yapılmasını sağlayan kod parçasıdır.

<strong>Retargeting</strong> : sitemize alışverişe giren birine ileri aşamalarda farklı yerlerde reklam göstererek onu geri dönmesini sağladığımız bir hedefleme sistemidir.

İki türlü retargeting vardır : <em>Pixel temelli</em> ve <em>Liste temelli</em>

<strong>Pixel temelli retargeting</strong> de, kullanıcının tarayıcısında javascript kodu çalıştırılır ve çerez ile kullanıcıya başka bir yerde reklam gösterilir.

<strong>Liste temelli retargeting</strong> de kullanıcının sitenizle etkileşim kurması gerekir. Üye olduğunda email adresi alınan kullanıcı tekrar bu email adresi yoluyla sosyal medya hesapları belirlenerek, bunlarla giriş yaptığı yerlerde, kullanıcılara reklamlar gösterilir.

<strong>Olay Kodu</strong> : Javascript koduna eklenen satırlardır. Kullanıcın hangi aşamada olduğunu retargeting sistemine bildirir.

Pixeldeki olay kodları şunlardır : <em>Search, ViewContent, AddCart, AddToWishList, IniateteCheckOut, AddPaymentInfo, Purchase,Lead</em>

<strong>ViewContent</strong> : Bir kullanıcının içeriği görüntülenmesi, o ürüne ilgi duyduğunu gösterir. Onun için görüntülenmede bu olay kodu çağrılır. (ürün/sayfa görüntüleme çağrılır)

<strong>Search</strong> : Bir kullanıcının sitenizde arama yapması, markanıza ve ürünlerinize ilgi duyduğuna işarettir. Bu kişiler birincil potansiyel müşterilerdir. (Aramalarda bu olay çağrılır.)

<strong>AddToCart : </strong>Sitenizden herhangi bir ürünü satın almaya karar verip, vazgeçmiş kişi, indirim ve kampanyalarda ilk hedeflenmesi gereken kişilerdir. (Bu olay sepete eklemede çağrılır.)

<strong>AddToWishlist</strong> : Site istek listesi oluşturmaya müsaitse, istek listesine ekleyen kullanıcılara o ürünle ilgili kampanyaları sunabilirsiniz. (istek listesine eklemede çağrılır)

<strong>InitiateCheckout</strong> : Sizden alışverişini tamamlayan, ürün sahibi olmuş müşteriniz için bu olay çağrılır. Bu kişileri yeni fırsatlardan haberdar edebilirsiniz. (alışverişi tamamla butonunda çağrılır)

<strong>AddPaymentInfo</strong> : Kişinin ödeme bilgilerini paylaşması size güven duyduğuna ve potansiyel müşteri olduklarına işaret eder.  (ödeme formu gönderme butonunda çağrılır)

<strong>Purchase</strong> : Sizden satın alma işlemini tamamen başarıyla tamamlamış müşteriler için kullanılır. Bu kişilerin sizden yeniden ürün olma ihtimalleri yüksektir. (satıl alma sonrası teşekkürler sayfasında çağrılır)

<strong>Lead</strong> : Sitenizde kullanıcılar yorum yapabiliyorsa, kullanıcının yorum yapması ürününüzden etkilendiği ve ürünü merak ettiğini işaret eder. (yorum gönderme butonunda çağrılır)

<strong>CompleteRegistration</strong> : Sitenize üye olma olayıdır. Birinin sitenize üye olması, ürününüzü almaya meyilli olduğunu gösterir. (kayıt formu gönderme butonunda çağrılır)
<pre>fpq('track','ViewContent');</pre>