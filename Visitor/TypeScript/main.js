/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */
define("DrawableShape", ["require", "exports"], function (require, exports) {
    "use strict";
});
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */
define("Point", ["require", "exports"], function (require, exports) {
    "use strict";
    var Point = (function () {
        function Point(x, y) {
            this.x = x;
            this.y = y;
        }
        Point.prototype.draw = function (renderer) {
            renderer.drawPoint(this);
        };
        Point.prototype.toString = function () {
            return "(" + this.x + ", " + this.y + ")";
        };
        return Point;
    }());
    exports.Point = Point;
});
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */
define("Line", ["require", "exports"], function (require, exports) {
    "use strict";
    var Line = (function () {
        function Line(p1, p2) {
            this.p1 = p1;
            this.p2 = p2;
        }
        Line.prototype.draw = function (renderer) {
            renderer.drawLine(this);
        };
        Line.prototype.toString = function () {
            return "(" + this.p1.toString() + ", " + this.p2.toString() + ")";
        };
        return Line;
    }());
    exports.Line = Line;
});
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */
define("Renderer", ["require", "exports"], function (require, exports) {
    "use strict";
    var Renderer = (function () {
        function Renderer() {
            this.shapes = [];
        }
        Renderer.prototype.addShape = function (shape) {
            this.shapes.push(shape);
        };
        Renderer.prototype.drawAll = function () {
            for (var _i = 0, _a = this.shapes; _i < _a.length; _i++) {
                var shape = _a[_i];
                shape.draw(this);
            }
        };
        Renderer.prototype.drawPoint = function (point) {
            console.log("Drawing point " + point.toString());
        };
        Renderer.prototype.drawLine = function (line) {
            console.log("Drawing line " + line.toString());
        };
        return Renderer;
    }());
    exports.Renderer = Renderer;
});
/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */
define("main", ["require", "exports", "Renderer", "Point", "Line"], function (require, exports, Renderer_1, Point_1, Line_1) {
    "use strict";
    var p1 = new Point_1.Point(1, 1);
    var l1 = new Line_1.Line(new Point_1.Point(1, 2), new Point_1.Point(4, 4));
    var renderer = new Renderer_1.Renderer();
    renderer.addShape(p1);
    renderer.addShape(l1);
    renderer.drawAll();
});
