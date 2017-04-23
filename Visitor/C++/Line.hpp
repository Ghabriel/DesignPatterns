#ifndef LINE_HPP
#define LINE_HPP

#include <ostream>
#include "DrawableShape.hpp"
#include "Point.hpp"
#include "Renderer.hpp"

class Line : public DrawableShape {
    friend std::ostream& operator<<(std::ostream&, const Line&);
 public:
    Line(const Point& p1, const Point& p2) : p1(p1), p2(p2) {}

 private:
    Point p1;
    Point p2;

    void onDraw(const Renderer& renderer) const override {
        renderer.draw(*this);
    }
};

inline std::ostream& operator<<(std::ostream& stream, const Line& line) {
    return stream << "(" << line.p1 << ", " << line.p2 << ")";
}

#endif
