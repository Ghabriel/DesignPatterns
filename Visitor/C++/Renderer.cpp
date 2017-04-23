#include <iostream>

#include "Renderer.hpp"

#include "DrawableShape.hpp"
#include "Point.hpp"
#include "Line.hpp"

void Renderer::addShape(const DrawableShape& shape) {
    shapes.push_back(shape);
}

void Renderer::drawAll() const {
    for (auto& shape : shapes) {
        shape.get().draw(*this);
    }
}

void Renderer::draw(const Point& point) const {
    std::cout << "Drawing point " << point << std::endl;
}

void Renderer::draw(const Line& line) const {
    std::cout << "Drawing line " << line << std::endl;
}
