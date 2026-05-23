// ✅ GOOD — Follows Open/Closed Principle
// AreaCalculator never changes.
// To add a new shape, just CREATE a new class — no editing old code.

#include <iostream>
#include <cmath>
#include <memory>
#include <vector>

// Abstract base
class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
public:
    double Width, Height;
    Rectangle(double w, double h) : Width(w), Height(h) {}
    double Area() const override { return Width * Height; }
};

class Circle : public Shape {
public:
    double Radius;
    Circle(double r) : Radius(r) {}
    double Area() const override { return M_PI * Radius * Radius; }
};

// ✅ New shape added WITHOUT touching any existing code
class Triangle : public Shape {
public:
    double Base, Height;
    Triangle(double b, double h) : Base(b), Height(h) {}
    double Area() const override { return 0.5 * Base * Height; }
};

class AreaCalculator {
public:
    // This method NEVER changes, no matter how many shapes you add
    double Calculate(const Shape& shape) const { return shape.Area(); }
};

// Usage:
// AreaCalculator calc;
// std::cout << calc.Calculate(Rectangle{5, 3}) << "\n";  // 15
// std::cout << calc.Calculate(Circle{4})       << "\n";  // 50.26...
// std::cout << calc.Calculate(Triangle{6, 4})  << "\n";  // 12
