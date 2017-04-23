<?php

require_once "DrawableShape.interface.php";

class Line implements DrawableShape {
	public function __construct(Point $p1, Point $p2) {
		$this->p1 = $p1;
		$this->p2 = $p2;
	}

	public function draw(Renderer $renderer) {
		$renderer->drawLine($this);
	}

	public function __toString() {
		return "(".$this->p1.", ".$this->p2.")";
	}

	private $p1;
	private $p2;
}

?>
