/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

import {DrawableShape} from "./DrawableShape"
import {Point} from "./Point"
import {Line} from "./Line"

export class Renderer {
	public addShape(shape: DrawableShape): void {
		this.shapes.push(shape);
	}

	public drawAll(): void {
		for (let shape of this.shapes) {
			shape.draw(this);
		}
	}

	public drawPoint(point: Point): void {
		console.log("Drawing point " + point.toString());
	}

	public drawLine(line: Line): void {
		console.log("Drawing line " + line.toString());
	}

	private shapes: DrawableShape[] = [];
}
