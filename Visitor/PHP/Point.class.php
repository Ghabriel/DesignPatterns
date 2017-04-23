<?php

require_once "DrawableShape.interface.php";

class Point implements DrawableShape {
	public function __construct($x, $y) {
		$this->x = $x;
		$this->y = $y;
	}

	public function draw(Renderer $renderer) {
		$renderer->drawPoint($this);
	}

	public function __toString() {
		return "(".$this->x.", ".$this->y.")";
	}

	private $x;
	private $y;
}

?>
