<?php

isset($_POST) && !empty($_POST) or die();

$data = array(
    "firstname" => $_POST['form-first-name'],
    "lastname" => $_POST['form-last-name'],
    "email" => $_POST['form-email'],
    "aboutyourself" => $_POST['form-about-yourself']
);

$connection = new MongoClient();
$collection = $connection->database->collectionName;

$collection->insert( $data );

header('Location: thankyou.html');
exit;
