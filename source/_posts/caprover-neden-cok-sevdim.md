---
title: Caprover 'i neden çok sevdim
author: farukcan
date: 2022-04-24 19:18:22
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - mühendislik
---

![Caprover-tutorial](https://pbs.twimg.com/media/EaflN1qWoAAYb94?format=jpg&name=4096x4096)

# Caprover
Kısacası, bu teknolojiyi docker kullandığınız projelerinizde işinizi birkaç tıka indirgeyeceğiniz bir upgrade olarak düşünebilirsin. 
Veritabanlarını, popüler docker applerini, wordpressi tek tık ile manage edebiliyorsunuz.
Digitalocean kullanıyorsanız hazır dropletinizi kullanıp kendi caprover vps'inizi kod kullanmadan oluşturabilisiniz.
Basit ve açık olması için listelerle anlatım yapacağım ;

#### Ne işe yarıyor?
- One-click apps ile Tek tıkla redis,postgres,wordpress ve yüzlerce bilinen teknoloji için docker containeri oluşturabiliyorsunuz. (aka : deploy)
- Domain ve subdomain işlerini kendi hallediliyor; Nginx ve letcrpyt kullandığı için domain ve subdomain yönlendirme ve onları https e çevirme işini otomatik hallediyor. Sadece containeri dışa açılacak portu belirtmeniz ve domaini girmeniz yeterli. (hatta one-click apps ile bu da otomatik yapılıyor)
- Containerların kendi arasındaki dosya paylaşımı için tagları otomatik oluşturabiliyorsunuz.
- Containerları dışarı açmadan kendi aralarında kolayca bağlayabiliyorsunuz.
- Nginx ile beraber websocket uygulamalarda kullanabiliyorsunuz.
- Birden fazla instance ile load balancing yapabiliyorsunuz.
- Basic auth ile projelere şifreyle erişim koyabiliyorsunuz.
- Env değerlerini ve portları caproverin kendi arayüzü üzerinden kolayca değiştirebiliyorsunuz.
- Daha detaylı container yönetimi için caproveri içine Portainer de kurabilirsiniz. Fakat bu tooldan sonra portainere ve docker-cliye gerek duymadım.
- Github action ile git projeniz ile caproveri bağlayabiliyorsunuz.
- Deploymentlar için versiyon kontrol sistemi var. Güncel sürüm hatalıysa bir önceki sürüme (image) dönebiliyorsunız.
- İçine gömülü Netdata ile istatiksel bilgilere erişebiliyorsunuz.
- Cluster: Birden fazla caprover sunucusunu beraber birbiriyle uyumlu çalıştırabiliyorsunuz.

![Caprover-tutorial](https://www.pedroalonso.net/static/5a972d3d7b95913d9fb2cb5981c84e97/fcda8/35.node.png)

#### Deploy yöntemleri
- One-click apps: Redis, postgres, wordpress, directus gibi yüzlerce işinize yarar appı tek tıkla kuruyorsunuz.
- Deploy via ImageName : Direkt image adını girerek app oluşturabilirsiniz. (dockerhubdaki herşeyi kısacası)
- Deploy captain-definition file : Captain-definition dosyası ile caproverin önceden ayarladığı appleri toplu halde (mesela kendi app'ınız ve mongodb beraber) kurabiliyorsunuz
- Deploy plain Dockerfile: Dockerfile içeriğini caprover'e giriyorsunuz, ve proje kolayca deploy oluyor.
- Deploy from Github/Bitbucket/Gitlab: caprover reponuzu takip edip, captain dosyasına bakar otomatik deploy ediyor.
- Tarball: bir captain dosyası içeren bir .tar dosyasını caprovera upload ederek uygulama deploy ediyorsunuz.
- Official CLI: Bilgisayarın caprover cli'si kuruluyorsa, proje klasörünüze girip, "caprover deploy" diyerek projenizi ayağa kaldırabiliyorsunuz. 

![Caprover-tutorial](https://www.pedroalonso.net/static/657e9cf1f88948c6e31dcc2c2a00c34e/fcda8/06.wp-form.png)

#### Benim caprover üzerindeki applerim:
- apprise : Bildirim sunucusu
- changedetection : bir web sayfasındaki değişimleri takip ediyor
- dozzle : docker containerlerinin loglarını erişmek için bir web arayüz.
- duplicati : veri yedekleme için harika bir çözüm.
- directus : "veritabanı ve api" kavramını tek bir sistem birleştiren harika bir şey.
- guacamole : ssh ve vnc sunucuları için güzel bir web arayüzü
- minio : amazon s3 alternatifi
- n8n : workflowlar ile otomasyon/integrasyon sistemi
- portainer : docker containerleri için bir web arayüzü
- wordpress : haltal olduğu için pek sevmesem de kendisini caprover üzerinden çok kolay blog oluşturabiliyorum.

Resmi sitesi : https://caprover.com
