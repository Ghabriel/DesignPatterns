#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <functional>
#include <vector>

class DrawableShape;
class Point;
class Line;

class Renderer {
 public:
    void addShape(const DrawableShape&);
    void drawAll() const;
    void draw(const Point&) const;
    void draw(const Line&) const;

 private:
    std::vector<std::reference_wrapper<const DrawableShape>> shapes;
};

#endif
