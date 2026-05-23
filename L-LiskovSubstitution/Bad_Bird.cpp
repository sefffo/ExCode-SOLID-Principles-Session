// ❌ BAD — Violates Liskov Substitution Principle
// Ostrich IS-A Bird in the real world, but it BREAKS the Bird contract in code.
// If someone passes an Ostrich where a Bird is expected, the app CRASHES.

#include <iostream>
#include <stdexcept>

class Bird {
public:
    virtual void Fly() { std::cout << "Bird is flying...\n"; }
    virtual ~Bird() = default;
};

class Sparrow : public Bird {
public:
    void Fly() override { std::cout << "Sparrow is flying...\n"; }
};

class Ostrich : public Bird {
public:
    // ❌ Throws — breaks the parent's contract!
    void Fly() override { throw std::logic_error("Ostriches can't fly!"); }
};

class BirdHandler {
public:
    void MakeBirdFly(Bird& bird) {
        bird.Fly(); // 💥 CRASH if bird is Ostrich
    }
};
