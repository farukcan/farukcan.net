---
ID: 489
title: Nesne Yönelimli Javascript
author: farukcan
date: 2016-06-16 23:06:22
post_excerpt: ""
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - javascript
  - oop
  - kalıtım
dsq_thread_id:
  - "4916122896"
---
Javascriptte, class(sınıf) yoktur. Onun yeri objeler vardır. Bu objeler class olarakta kullanılabilir.
{% codeblock lang:js %}
// Hayvan sınıfı değişkenleri ve constructor
function Hayvan(yaş){
	this.yaş = yaş;
	console.log("Yeni hayvan");
}

// Hayvan sınıfı metodları
Hayvan.prototype.büyü = function(){
		this.yaş++;
}

// Insan sınıfı değişkenleri ve constructor
function Insan(yaş){
	Hayvan.call(this,yaş); // super classın constructorünü çağır
	console.log("Yeni Insan");
}

// Kalıtım - prototipleri birleştir
Insan.prototype = Object.create(Hayvan.prototype);
Insan.prototype.constructor = Insan;

// Insanı sınıfının kendine özgü metodları
Insan.prototype.konuş = function(){
	console.log("Ben "+this.yaş+" yaşıdayım");
}

// Test
var ahmet = new Insan(16);
ahmet.büyü();
ahmet.konuş();
console.log(ahmet)

{% endcodeblock %}


Object.create fonksiyonu, bir objeyi kopyalamaz, sadece adresleme yaparak , yeni bir obje oluşturur.(delegasyon) Bunun sayesinde, kalıtım yaparken hafıza kullanımını azaltırız.

<strong>this</strong> deyimiyle javascriptte, sınıfın kendisi kastedilmez. Bir fonksiyonun hangi obje üzerinde çağrıldığı kastedilir.  <strong>obje.fonksiyon(); </strong>yani o fonksiyonun içinde this kullanıldıysa, noktanın solundaki ilk ifade olan <strong>obje </strong>,this'e karşılık düşer. Buda javascriptin önemli farklarında biridir.

Bir fonksiyondan sonra <strong>call </strong>kullanılırak, o fonksiyonundaki this ifadesi, istediğimiz obje ile yer değiştirebiliriz.

{% codeblock lang:js %}
obje1.fonksiyon(); // burda this=obje1
obje2.fonksiyon.call(obje3); // burda this=obje3
{% endcodeblock %}
