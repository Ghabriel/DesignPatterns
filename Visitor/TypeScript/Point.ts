/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

import {DrawableShape} from "./DrawableShape"
import {Renderer} from "./Renderer"

export class Point implements DrawableShape {
	constructor(x: number, y: number) {
		this.x = x;
		this.y = y;
	}

	public draw(renderer: Renderer): void {
		renderer.drawPoint(this);
	}

	public toString() {
		return "(" + this.x + ", " + this.y + ")";
	}

	private x: number;
	private y: number;
}
