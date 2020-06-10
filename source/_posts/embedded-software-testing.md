---
title: Embedded Software Testing
author: farukcan
date: 2020-06-10 17:19:22
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - embedded
  - test
  - testing
  - gömülü
---

# Gömülü Yazılım Testi

## Özet

Bu yazıda, "Gömülü yazılım nedir?", "Gömülü yazılım testleri neden önemlidir?", "Gömülü yazılım nasıl test edilir?", "Gömülü Yazılımda TDD nasıl yapılır?", "Standart yazılım testinden farkları nedir?" gibi soruların cevapları işlenmektedir.

## Gömülü Yazılım Nedir?

Gömülü yazılımlar , gömülü sistem diye bilinen kontrol aygıtları ve makineleri için bilgisayar yazılımlarıdır.

Gömülü sistem bir görev için atanmış, mekanik ve elektronik fonksiyonları yerine getiren işlemciden, hafızadan, girişler,çıkışlardan oluşan bir bilgisayar sistemidir.

Endüstriyel robotlar, GPS alıcıları, Kameralar, Routerlar, Oyun konsolları, Fotokopi makineleri, Arabalar, Akıllı cihazlar, Saatler, Mikrodalga fırınları, Beyaz eşyalar, Trafik Işıkları, İHAlar, Telefonlar, Tabletler, Askeri cihazlar, Hava araçları bir gömülü sistemdir.

Son istatistiklere göre tahminen dünyadaki işlemcilerin %90'ına yakını bir gömülü sistem parçasıdır.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled.png)

## Gömülü yazılım testi neden önemlidir?

Gömülü sistemler hayatımızın her aşamasına girmiştir. Bunlardaki bir kusur, hata ve zayıflık can güvenliğimizi bile tehdit edebilecek seviyelere gelebilmektedir. Geçtiğimiz yıllarda, Chrysler adında birçok ünlü markaların sahibi olan bir firma, arabalarının uzaktan hacklenebilme zayıflığı yüzünden 1.4 milyon arabayı geri çağırmıştır. Bu arabalar yapılacak siber saldırılarla sürücüyü öldürecek ciddiyette riskler taşımaktadır.

Yine geçtiğimiz yıllarda Toyotanın güç sisteminde hiçbir test ve belgeleme içermeyen spagetti kodlar ortaya çıkmıştır.

İngiltere de satılan bir akıllı termostat sistemi, yazılımındaki bir bug sebebiyle müşterileri soğuğa mazur bırakmıştır. Bir can kaybı yaşanmasa da, bu bug bebekler için ölümcül olabilirdi.

Bir Airbus A400M uçağı, gömülü sistemindeki bir bug sebebiyle düşmüştür. Bu boyutta bir uçağın askeri mühimmat taşıması ve yerleşim yerlerine düşmesi büyük can kayıplarına yol açabilirdi.

Gömülü sistemler hastanelerde de kullanılmaktadır. Bir hastanın ilaç pompasını kontrol eden yazılımda bug bulunmuştur. Bu bug sebebiyle, hastalara ölümcül doz verilebilirdi.

Ayrıca gömülü sistemler birbirine bağlı olduğu için birindeki kusur diğerlerini de etkileyebilir. Geçtiğimiz yıllarda bir WiFi destekli Akıllı Lambada bir güvenlik açığı bulunmuştur. Bu açık sayesinde hackerlar WiFi şifresine erişip, bütün evin ağına sızabilmekteydi.

Uzay mekikleri ve roketlerde bir gömülü sistemdir. Geçtiğimiz yüzyıllarda gömülü yazılım kusurları sebebiyle, birçok uzay faciası yaşanmıştır.

Bu sebeplerden dolayı, gömülü yazılım testi, standart yazılım testlerinden ayrılır. Çünkü bir hata, kusur, açık ve zayıflık bizi öldürebilir.

Sektörlere göre gömülü yazılım test tekniği paper sayısı

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%201.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%201.png)

**Test Nedir?**
Test bugların, kusurların, noksanlıkların ve zayıflıkların bulunmasıdır.

## Gömülü yazılım nasıl test edilir?

Benzer bir çok yazılım test sisteminde olduğu gibi, gömülü yazılımda da test geliştirme döngüsünün ayrılmaz bir parçasıdır.

Sağlamlık için hem fonksiyonel hemde fonksiyonel-olmayan nitelikler denetlenmelidir. 

**Fonksiyonel Nitelik Testi**, yazılım yerine getirmesi gereken görevleri kusursuz bir şekilde yapmasıyla alakalıdır. Gömülü yazılımda fonksiyonellik fiziksel çevreye bağlı kontrol ediliyor olabilir. Bu çevresel girdilerin tanımı ve aralığı açık olmalıdır. 

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%202.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%202.png)

Örnek kodda, fonksiyon çevresel bir girdi olan ivmeölçer ile kontrol edilmektedir. Fakat bu fonksiyonun ivmelenme girdilerinden biri "0" değeri aldığında bozulacaktır.

Fiziksel çevre, rastgele oluşturulan sentetik girdiler ile simüle edilebilir. Fakat bu yaklaşımda ilişkili girdi sentezlemek başarısız olabilir. Bunun önüne geçmek için bu simülasyon evrimsel veya metaheuristic algoritmalar ile yapılabilmektedir.

Gerekli olan durumlarda tüm olası girdiler test edilebilir. Fakat çok önemli olmayan fonksiyonlarda, bu yöntem maliyetlidir. (zaman açısından)

Anlaşılacağı üzere girdi uzayı ve bu uzayın test edilebilirliği ve test yöntemleri büyü önem taşımaktadır.

**Fonksiyonel Olmayan Nitelik Testi** , bir gömülü yazılımın birkaç fonksiyonel olmayan nitelikleri vardır. Bunlardan en önemli ve temel nitelikler : zamanlama, enerji ve güvenirliktir. ( timing, energy, reliability)

***Zaman Kısıtlamaları***, yazılımın görevlerini kısıtlı zamanda tamamlanmasıyla alakalıdır. Gömülü yazılımların çoğu gerçek zamanlıdır. Tepki süreleri ve gecikmeleri çok önemlidir. Örneğin bir arabanın kaza anında darbe sensörlerindeki verilere göre hava yastıklarını doğru zamanda tetiklemesi hayati önem taşır. Bir kaza olduğunun doğrulanması, emin olunması, hesaplamaların yapılması ve çok geç olmadan hava yastığın tetiklenmesi, milisaniyeler düzeyinde kısıtlı bir zamanda yapılmalıdır.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%203.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%203.png)

Dolasıyla bu süreleri optimize ederken, işlemcinin kod talimatları işleme süresi bilenerek yazılım geliştirilmelidir.

Her bir fonksiyon için bir "zaman bütçesi" belirlenmeli ve o fonksiyon o zamanı aşmayacak şekilde optimize edilmelidir.

İşlemciler, boolean operatorlerini çok hızlı işler, toplama işlemini çarpmaya göre daha hızlı yapar. Hafızaya erişmek bile zaman tüketir.

İşlemci-hafıza arasında zaman kaybı olmaması için işlemcinin önbelleği kullanılmalıdır.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%204.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%204.png)

Her bir fonksiyonun zamanını ölçen testler yazılmalıdır. 

Örneğin: `assert(time <¼ 1ms)`

Her bir önemli fonksiyon için WCET (Worst-case execution time) yani en kötü senaryoda çalışma zamanı bilinmelidir.

***Enerji Kısıtlamaları,*** zaman gibi gömülü yazılımda göz önünde bulundurulması gerek şeylerden biridir. Özellikle batarya kaynaklı sistemlerde önemlidir. Enerji tükenen işlemlerin, komponentlerin tüketim değerlerin testi yazılmalıdır. Zaman kısıtlamalarında olduğu gibi, enerji tüketimi içinde, WCEC (worst case energy consumption) yani en kötü enerji tüketim senaryosu ölçülmelidir.

***Güvenirlik Kısıtlamaları,*** gömülü sistemler çoğu zaman fiziksel çevreyle etkileşim içindedir. Fiziksel çevreden sensörler ile güvenilebilir veriler elde etme çalışır. ( jiroskop , ivmeölçer, kablosuz iletişim vs. ) Ancak bu sensörlerden ve alıcılardan tutarsız veriler alınabilir. Ağda veri paketleri bozulabilir, kaybolabilir. Çoğu sensör kusursuz değildir ve hata payları vardır. Ayrıca daha tutarlı, kaliteli sensör ve alıcı sistemler pahalıdır. İşte burada bu çevresel verilerin kabul edilebilir tutarlılık seviyeleri belirlenmeli ve ona göre bir yazılım geliştirilmelidir.

## Test Metodolojilerin Kategorizasyonu

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%205.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%205.png)

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%206.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%206.png)

**Kara-kutu Soyutlaması**: Sistem kara kutu gibi davranır. Test senaryoları örnekler ve rastgele girdiler ile oluşturulur. Sistemin gereksinimleri test edilir. Fonksiyonlar test edilir. Sık rastlanmayan uç senaryolar test edilemeyebilir.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%207.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%207.png)

**Gri-Kutu Soyutlaması**: Kara-kutu ve Beyaz-kutu yaklaşımın karışımı olarak düşebilir. Ancak sistem kara kutu gibi davranmış, bir model gibi temsil edilir. Bilgiyle alakalı özellikler test edilir. Testler arama uzayına göre oluşturulur.

**Beyaz-kutu Soyutlaması**: Bütün kaynak kodunun ve yollarının test edildiği bir işlemdir. Girdi uzayına göre testler yazılır. Daha çok sistem yapısı test edilir. Bu yöntemde eksik özellikler tespit edilemez.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%208.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%208.png)

## Yapısal olmayan yaklaşımlar

Bu yöntemlerde bir düzel ve yapı yoktur. Testin kalitesi testi yapana bağlıdır. Yazılımın ne kadar test edildiğini bilmek zordur. Bu bu testin sonuçları objektif değildir. Çok taraflı ve görecelidir.

### Smoke Testing (Duman testi)

Yazılımın bir çok ana fonksiyonun çalıştırılıp duman çıkıp çıkmadığın test edilmesidir. (Bu daha hardwarelar için yapıldığı böyle tanımlanıyor. Tabi duman çıkıp çıkmaması değil, fonksiyonu yerine getirip getirmemesi test edilir)

Geniş ve sığ bir yaklaşımdır

### Exploratory Testing (Keşifsel yaklaşım)

Uzman bir tester, sistemin açıklarını bulmayı sistemi alt etmeye çalışır.

Learn(Öğren), Design(Tasarla), Execute(Uygula), Analysis(Sonuçları analiz et) diye 4 aşaması vardır.

Bu çok dağınık bir yöntemdir.

## Testing Coverage

Bir yazılımın, test senaryolarının yüzde kaçını başarıyla tamamladığını gösteren değerdir.

%100 coverage, yazılım 100% test edilmiş olduğunu göstermez, çünkü test-caselere bağlıdır.

Aynı şekilde 100% test edilmiş bir yazılım 100% güvenli de değildir.

## Test geliştirme döngüsü

### TDD (Test Driven Development)

1. Testleri oluştur.
2. Bütün testleri çalıştır, hatalı olanı gör.
3. Ufak(!) değişiklikler ile hatayı düzelt.
4. Testi yeniden çalıştır. Testin geçildiğini gör.
5. Testleri refactor et. Fazlalıkları kaldır.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%209.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%209.png)

### TDD ve Gömülü Yazılım

- Testlerde donanıma bağlılık vardır.
- Gerçek zamanlılıktan gelen zaman kısıtlamaları kısıtlamalar vardır.
- Sınırlı bir hafıza vardır. (Normal yazılama göre)
- Pek OOP(Nesneye yönelimli programlama) kullanamazsın.

### V-model

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%2010.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%2010.png)

### Unit Test

Yazılımın her bir çalıştırılabilir fonksiyonunun test edilmesidir.

### Integration Test (Subsystem Test)

Yazılım her modülünün test edilmesi ve bu modüllerin uyumluluklarında test edilmesidir.

### Software Test (System Test)

Sistemin bir bütün olarak test edilmesidir.

### Acceptance Test

Müşteriyle beraber yapılan, yazılım kabul edilebilirliğinin testidir.

## Emulated Target Board

Gömülü yazılımlar test edilirken ve geliştirirken, sanal donanım kartları kullanılır. Çünkü bir hata yüzünden kart bozulabilir ve kullanılamaz hale gelebilir.

Sanal kartlar yoksa, bu kartları mocklayan bir yazılım yazılarak testler çalıştırılabilir. Fakat bunu donanımdan bağımsız yazılım parçaları için yapmak gerekir.

![Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%2011.png](Embedded%20Software%20Testing%208ce61930ef9e4ed194dae1d782f2b091/Untitled%2011.png)


# Sunum
[Embedded Software Testing Sunum](https://docs.google.com/presentation/d/1fFRhwwksglVttGgJCxI786ryusi4gHlaBj1FOQTgf8Y/edit?usp=drivesdk)

# Kaynakça ve İleri Okuma

**[On Testing Embedded Software](https://www.comp.nus.edu.sg/~abhik/pdf/TestingEmbeddedSoftware.pdf)**
Abhijeet Banerjee*, Sudipta Chattopadhyay†
, Abhik Roychoudhury*

**[What we know about testing embedded software?](http://158.64.76.181/bitstream/10993/31857/1/What%20we%20know%20about%20testing%20embedded%20software.pdf)**
Vahid Garousi, Hacettepe University and University of Luxembourg
Michael Felderer, University of Innsbruck
Çağrı Murat Karapıçak, KUASOFT A.Ş.
Uğur Yılmaz, ASELSAN A.Ş.

**[Automating Embedded Software Testing on an Emulated Target Board](https://dl.acm.org/doi/pdf/10.1109/AST.2007.7?download=true)**
Jooyoung Seo, Ahyoung Sung, Byoungju Choi, Sungbong Kanga
Dept. of Computer Science and Engg., Ewha University, Seoul, Korea
Mobile Solution, System LSI Division, Samsung Electronics Co., Ltd., Yongin, Koreaa
{jyseo, aysung}@ewhain.net, bjchoi@ewha.ac.kr, osbkang@samsung.com

**Formal Testing Applied in Embedded Software**
Li Zhen,Liu Bin, Ma Ning and Yin Yongfeng
Dept. of System Engineering of Engineering Technology
Beihang University
No.37 Xueyuan Road, Beijing, China, 100191

**[The Effectiveness of Real-time Embedded Software
Testing](http://home.iitj.ac.in/~saurabh.heda/Papers/Research%20Papers/2011/Untitled%20Folder/Effectiveness%20of%20Real%20time%20Embedded%20software%20Testing%202011.pdf)**
Bo Zhang,Xiangheng Shen
Changchun Institute of Optics, Fine Mechanics and Physics
Chinese Academy of Sciences
Changchun, China

**[Embedded Software
Testing](http://www.archive.ece.cmu.edu/~ece649/lectures/10_testing.pdf)**
Distributed Embedded Systems
Philip Koopman
September 30, 2015

**[Tool Support for Automated Traceability of
Test/Code Artifacts in Embedded Software Systems](https://www.researchgate.net/profile/Vahid_Garousi2/publication/254018254_Tool_Support_for_Automated_Traceability_of_TestCode_Artifacts_in_Embedded_Software_Systems/links/56ba643f08ae0a6bc9556b3d/Tool-Support-for-Automated-Traceability-of-Test-Code-Artifacts-in-Embedded-Software-Systems.pdf)**
Christian Wiederseiner, Vahid Garousi, Michael Smith
Department of Electrical and Computer Engineering, University of Calgary
2500 University Drive NW, Calgary, AB Canada T2N 1N4

**[Embedded Software Testing in Research
Environment](https://www.researchgate.net/profile/Marcin_Bajer/publication/279184152_Embedded_software_testing_in_research_environment_A_practical_guide_for_non-experts/links/558d62a808ae817475e63812/Embedded-software-testing-in-research-environment-A-practical-guide-for-non-experts.pdf)**
Marcin Bajer, Marek Szlagor, Marek Wrzesniak
ABB Corporate Research Center
Krakow, Poland

**[Effective Test Driven Development for Embedded Software](https://pdfs.semanticscholar.org/73e6/c4d62e1a3fb09ee72f77688013086e970779.pdf)**
Michael J. Karlesky, William I. Bereza, and Carl B. Erickson, PhD

**[Test Driven Development for Embedded Software](https://www.renaissancesoftware.net/files/articles/ESC-241Paper_Grenning-v1r1.pdf)**
James Grenning
San Jose, April 2007, ESC Class# 241
