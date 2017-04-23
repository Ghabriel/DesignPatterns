#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>
#include "DrawableShape.hpp"
#include "Renderer.hpp"

class Point : public DrawableShape {
    friend std::ostream& operator<<(std::ostream&, const Point&);
 public:
    Point(double x, double y) : x(x), y(y) {}

 private:
    double x;
    double y;

    void onDraw(const Renderer& renderer) const override {
        renderer.draw(*this);
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Point& point) {
    return stream << "(" << point.x << ", " << point.y << ")";
}

#endif
