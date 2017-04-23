<?php

class Renderer {
    public function addShape(DrawableShape $shape) {
        $this->shapes[] = $shape;
    }

    public function drawAll() {
        foreach ($this->shapes as $shape) {
            $shape->draw($this);
        }
    }

    public function drawPoint(Point $point) {
        echo "Drawing point ".$point."<br>";
    }

    public function drawLine(Line $line) {
        echo "Drawing line ".$line."<br>";
    }

    private $shapes = [];
}

?>
