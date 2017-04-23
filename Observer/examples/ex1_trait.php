<?php
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

require "../impl_trait.php";

class Message {
    public function __construct($content) {
        $this->content = $content;
    }

    public function getContent() {
        return $this->content;
    }

    private $content;
}


class UserEntranceEvent {
    public function __construct($username) {
        $this->username = $username;
    }

    public function getUsername() {
        return $this->username;
    }

    private $username;
}


class MessageSource implements Observable {
    use ObservableTrait;
    public function run() {
        $this->notifyObservers(new Message("Hello, world!"));
    }
}


class UserEntranceSource implements Observable {
    use ObservableTrait;
    public function run() {
        $this->notifyObservers(new UserEntranceEvent("admin"));
    }
}


class Chat implements Observer {
    public function notify($data) {
        if ($data instanceof Message) {
            echo "Received message: ".$data->getContent()."<br>";
        } else if ($data instanceof UserEntranceEvent) {
            echo "A user entered the chatroom: ".$data->getUsername()."<br>";
        }
    }
}
?>

<html>
<body>

<?php
$chat = new Chat();
$messageSource = new MessageSource();
$userEntranceSource = new UserEntranceSource();

$messageSource->addObserver($chat);
$userEntranceSource->addObserver($chat);

$messageSource->run();
$userEntranceSource->run();

$userEntranceSource->removeObserver($chat);

$messageSource->run();
$userEntranceSource->run();
?>

</body>
</html>
