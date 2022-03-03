<?php

	define( 'DB_NAME', 'wordpress' );
	define( 'DB_USER', 'root' );
	define( 'DB_PASSWORD', '' );
	define( 'DB_HOST', 'localhost' );
	define( 'DB_CHARSET', 'utf8' );
	define( 'DB_COLLATE', '' );

	define('AUTH_KEY',         'qU&@[#0{rm1:Kc2A7]wm#XDp++BDsP!^PpO45RWJQ|MV~pp/_ycVR )U{A y`&?P');
	define('SECURE_AUTH_KEY',  'E.!-y5a-|3k/r(E0K2@ @}0&6SAZ)5:#ZkP5|/+DSc8y>3f _wl LGAr/kV$+2Rk');
	define('LOGGED_IN_KEY',    '=p|7iO([9X^u9oJ5l^Eny>! FIp0V8((q: i0IM*xR Ua0w#s|d:TI5vs4MyTA$@');
	define('NONCE_KEY',        ';i*P^K)&$vD-e^+y6uCrhx+m-~(c|o{z4l;V^,-/+?L1FSL<yvDjd.a-/ 7]F5Py');
	define('AUTH_SALT',        '|3{;X L?E6o<R-/3Z854 ?Oo-n $vFkK69NEam%3S3aBHQIa_)HShQn.m -hT G(');
	define('SECURE_AUTH_SALT', ']5O]<(U-0L{i^ #v Y^d 3|RNM+G`H.Gd)^XsIKV!#)3Mg|g5xl(C7-B>*8Z)0|W');
	define('LOGGED_IN_SALT',   'EBDQOyImPzM`Q0Io`^9R;Igf*+0u*,OBr(g|+r$i3Uwa5OTd58f A;9/|,df%Ch(');
	define('NONCE_SALT',       '#On4yLZyQeZmc1Rt>-o?=p3g|*jt?|wI+m-K`4+2+F<8GU=|IxkO$e?|^8[9y8h6');

	$table_prefix = 'wp_';

	define( 'WP_DEBUG', false );

	if ( ! defined( 'ABSPATH' ) )
	{
		define( 'ABSPATH', __DIR__ . '/' );
	}

	require_once ABSPATH . 'wp-settings.php';
