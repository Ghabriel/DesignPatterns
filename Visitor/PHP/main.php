<html>
<body>

<?php

require_once "Renderer.class.php";
require_once "Point.class.php";
require_once "Line.class.php";

$p1 = new Point(1, 1);
$l1 = new Line(new Point(1, 2), new Point(4, 4));

$renderer = new Renderer();
$renderer->addShape($p1);
$renderer->addShape($l1);
$renderer->drawAll();

?>

</body>
</html>
