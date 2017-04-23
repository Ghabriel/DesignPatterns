<?php
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

interface Observer {
    public function notify($data);
}

interface Observable {
    public function notifyObservers($data);
    public function addObserver(Observer $observer);
    public function removeObserver(Observer $observer);
}

trait ObservableTrait {
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
