<?php

interface Observer {
    public function notify($data);
}

class Observable {
    public function notifyObservers($data) {
        foreach ($this->observers as $observer) {
            $observer->notify($data);
        }
    }

    public function addObserver(Observer $observer) {
        $this->observers[] = $observer;
    }

    public function removeObserver(Observer $observer) {
        $count = count($this->observers);
        for ($i = 0; $i < $count; $i++) {
            if ($this->observers[$i] == $observer) {
                array_splice($this->observers, $i, 1);
                break;
            }
        }
    }

    private $observers = [];
}

?>
