---
ID: 556
title: map fonksiyonu nedir, ne işe yarar ?
author: farukcan
date: 2016-09-26 14:57:09
post_excerpt: ""
layout: post
published: true
category:
  - Yazılım
tags:
  - yazılım
  - map
  - csharp
  - javascript
dsq_thread_id:
  - "5174352499"
---
İki tür map fonksiyon vardır:
<ul>
	<li>Değerler için <strong>map</strong> : bir değerin, 2 nokta arasındaki konumu, başka iki nokta arasına oranlar.</li>
	<li>Diziler için <strong>map</strong> : bir fonksiyonu bütün dizi elemanlarına uygulayarak yeni dizi oluşturur.</li>
</ul>
<h2>map(değer,başlangıç,bitiş,yenibaşlangıç,yeniBitiş)</h2>
değerin, 2 nokta arasındaki konumu, başka iki nokta arasına oranlar

<strong>map</strong>(<span style="color: #0000ff;">2</span>,<span style="color: #ff0000;">1,3,</span><span style="color: #99cc00;">2,6</span>) = 4

<strong>map</strong>(<span style="color: #0000ff;">Math.random()</span>,0,1,-25,75) = -25 ve 75 arası rastgele değer
<h2>Array.map(fonksiyon)</h2>
bir fonksiyonu bütün dizi elemanlarına uygulayarak yeni dizi oluşturur.

[<span style="color: #0000ff;">1,2,3,4</span>].map(<span style="color: #99cc00;">Math.sqrt</span>) = [1,4,9,16]
{% codeblock lang:js %}
var array = [ 2 , 3 , 5, 6]

var yeniArray = array.map(function(a){ return a*a+1 });

// yeniArray = [5,10,26,37]
{% endcodeblock %}

C# map fonksiyonu
{% codeblock lang:csharp %}
    float map(float val, float iMin, float iMax, float oMin, float oMax) {

        return (val - iMin) * (oMax - oMin) / (iMax - iMin) + oMin;
    }
{% endcodeblock %}
