/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

import {DrawableShape} from "./DrawableShape"
import {Point} from "./Point"
import {Renderer} from "./Renderer"

export class Line implements DrawableShape {
	constructor(p1: Point, p2: Point) {
		this.p1 = p1;
		this.p2 = p2;
	}

	public draw(renderer: Renderer): void {
		renderer.drawLine(this);
	}

	public toString() {
		return "(" + this.p1.toString() + ", " + this.p2.toString() + ")";
	}

	private p1: Point;
	private p2: Point;
}
