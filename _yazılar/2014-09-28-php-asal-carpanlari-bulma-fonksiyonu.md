---
ID: 132
post_title: PHP Asal çarpanları bulma fonksiyonu
author: farukcan
post_date: 2014-09-28 15:39:59
post_excerpt: ""
layout: post
permalink: >
  http://farukcan.net/genel/2014/09/php-asal-carpanlari-bulma-fonksiyonu/
published: true
dsq_thread_id:
  - "4083741215"
---
<a href="http://farukcan.net/wp-content/uploads/2014/09/hqdefault.jpg"><img src="http://farukcan.net/wp-content/uploads/2014/09/hqdefault.jpg" alt="hqdefault" width="480" height="360" class="alignnone size-full wp-image-215" /></a>
<pre lang="php">

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

</pre>