<?php

$connection = new MongoClient();
$collection = $connection->database->collectionName;
$cursor = $collection->find();

echo "<html><body>";

foreach ( $cursor as $id => $value )
{
    echo "<span>";
    echo $value["aboutyourself"] . "<br>";
    echo "</span>";
}

echo "</html></body>";
