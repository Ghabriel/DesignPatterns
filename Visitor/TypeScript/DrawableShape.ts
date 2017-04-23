/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

import {Renderer} from "./Renderer"

export interface DrawableShape {
	draw(renderer: Renderer): void;
}
