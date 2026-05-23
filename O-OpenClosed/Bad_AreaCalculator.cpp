// ❌ BAD — Violates Open/Closed Principle
// Every time you add a new shape, you have to EDIT this method.
// What happens when you add Triangle, Hexagon, Pentagon...?

#include <iostream>
#include <cmath>
#include <variant>

struct Rectangle { double Width, Height; };
struct Circle    { double Radius; };

class AreaCalculator {
public:
    double Calculate(const std::variant<Rectangle, Circle>& shape) {
        if (auto* r = std::get_if<Rectangle>(&shape))
            return r->Width * r->Height;
        else if (auto* c = std::get_if<Circle>(&shape))
            return M_PI * c->Radius * c->Radius;
        // ❌ Adding Triangle means editing this method again
        return 0;
    }
};
