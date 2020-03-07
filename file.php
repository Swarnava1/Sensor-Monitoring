<?php 
	$file=fopen("data", "w");
	$txt=$_GET['state'];
	fwrite($file, $txt);
	fclose($file);

	header('Location: project.html');
?>