#include "Renderer.hpp"
#include "Point.hpp"
#include "Line.hpp"

int main(int, char**) {
    Point p1 = {1, 1};
    Line l1 = {{1, 2}, {4, 4}};

    Renderer renderer;
    renderer.addShape(p1);
    renderer.addShape(l1);
    renderer.drawAll();
}
