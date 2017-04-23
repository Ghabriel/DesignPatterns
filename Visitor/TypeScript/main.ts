/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

import {Renderer} from "./Renderer"
import {Point} from "./Point"
import {Line} from "./Line"

let p1 = new Point(1, 1);
let l1 = new Line(new Point(1, 2), new Point(4, 4));

let renderer = new Renderer();
renderer.addShape(p1);
renderer.addShape(l1);
renderer.drawAll();
