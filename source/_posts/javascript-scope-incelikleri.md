ID: 493
title: Javascript Scope İncelikleri
author: farukcan
post_excerpt: ''
layout: post
category:
  - Yazılım
tags:
  - yazılım
  - javascript
  - oop
published: true
dsq_thread_id:
  - '4916142080'
date: 2016-06-16 23:14:39
---
Bir fonksiyon veya değişken, oluşturulduğu yerin scopeuna dahildir. Kullanıldığı yerin değil.
{% codeblock lang:js %}
var random = function(){
	return Math.floor(Math.random()*100);
}
var sagas = [];
var hero = "faruk"+random(); // faruk7

var newSaga = function(){
	var foil = "thefoil"+random();
	sagas.push(function(){
		var deed = "thedeed"+random();
		console.log(hero+deed+foil);
	});
};

newSaga();
sagas[0](); // faruk7 thefoil2 thedeed1
sagas[0](); // faruk7 thefoil2 thedeed4
newSaga();
sagas[0]();  // faruk7 thefoil2 thedeed5
sagas[1]();  // faruk7 thefoil9 thedeed6
sagas[0]();  // faruk7 thefoil2 thedeed7
sagas[1]();  // faruk7 thefoil9 thedeed8

// burdan anlaşıldığı üzere, bir fonksiyonun scopunu , oluşturulduğu yer belirliyor.
// yani sonrasında kullandıldığı scopre değil

// mesela burdaki foil değeri, ilk defa fonksiyonun tanımlandığı foil değeri
// newsagadan sonra, foil güncellenmiyor, yeni foil oluşuyor.
// sagas[0] eski foil değerini döndürecektir.</pre>
{% endcodeblock %}