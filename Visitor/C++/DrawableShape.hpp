#ifndef DRAWABLE_SHAPE_HPP
#define DRAWABLE_SHAPE_HPP

class Renderer;

// Utilizes the Non-Virtual Interface (NVI) idiom
class DrawableShape {
 public:
    void draw(const Renderer& renderer) const {
        onDraw(renderer);
    }

 private:
    virtual void onDraw(const Renderer&) const = 0;
};

#endif
