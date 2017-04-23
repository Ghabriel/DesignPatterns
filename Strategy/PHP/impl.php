<?php
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

interface Logger {
    public function log($message);
}


class PrintLogger implements Logger {
    public function log($message) {
        echo $message."\n";
    }
}


// Note that this is an example of the Null Object pattern
class NullLogger implements Logger {
    public function log($message) {}
}


class Database {
    public function __construct(Logger $logger) {
        $this->logger = $logger;
    }

    public function execute($query, array $params) {
        $this->logger->log("Query: ".$query."\nParams: ".json_encode($params));
    }

    private $logger;
}

?>

<html>
<body>

<pre>
<?php

$logger = new PrintLogger();
$connection = new Database($logger);

$connection->execute("SELECT `name` FROM `users` WHERE `id`=:id", [
    "id" => 42,
]);

$connection->execute("UPDATE `users` SET `name`=:name WHERE `id`=:id", [
    "id" => 42,
    "name" => "admin"
]);

echo "Finished";

?>
</pre>

</body>
</html>
