<?php
if(!isset($_GET['q'])) {
setcookie("data",base64_encode(serialize(array(
"secret" => "bdf2284c7b25e754cab8828c684c2ef845d1559530674674e73bbc6f38fa54a2"))));
// very very very long >o<
}
else
{
$data = unserialize(base64_decode($_COOKIE['data']));
if($data['secret'] != hash("sha256",$_GET['q']))
    header('Location: http://tfairane.com');
echo "YOU CANT SEE ME ! :D";
}
?>
