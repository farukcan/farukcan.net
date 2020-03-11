---
ID: 132
title: PHP Asal çarpanları bulma fonksiyonu
author: farukcan
date: 2014-09-28 15:39:59
post_excerpt: ""
layout: post
published: true
category:
  - Yazılım
tags:
  - php
  - asal
  - yazılım
dsq_thread_id:
  - "4083741215"
---
{% codeblock lang:php %}
<?php

//fonksiyonumuzu deneyelim : mesala 20'nin asal çarpanları
var_dump(asalcarpanbul(20));


// Bu fonksiyon sana bir sayının asal çarpanlarını array halinde döndürür
function asalcarpanbul($x){
	## asalcarpanbul() :  asal carpan bulma fonksiyonu by faruk can /farukcan.net
	$x_guncel = $x;
	$asalsayilar = Array();
	$carpanlar = Array();
	for($i=2;$i<=$x;$i++){
		$bolenadet = 0;
		for($m=1;$m<=$i;$m++){
			if($i%$m==0) $bolenadet++;
		}
		if($bolenadet == 2){
			array_push($asalsayilar, $i);
		}
	}
	foreach ($asalsayilar as $asal) {
		while($x_guncel%$asal==0){
			array_push($carpanlar, $asal);
			$x_guncel= $x_guncel/ $asal;
		}
	}

	return $carpanlar;
} // fonksiyon sonu

?>
{% endcodeblock %}
