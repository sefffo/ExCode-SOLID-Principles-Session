// ✅ GOOD — Follows Liskov Substitution Principle
// We model the hierarchy based on BEHAVIOR, not just real-world categories.

#include <iostream>

// Base class: all birds share these behaviors
class Bird {
public:
    virtual void Eat()       = 0;
    virtual void MakeSound() = 0;
    virtual ~Bird() = default;
};

// Only birds that CAN fly extend this
class FlyingBird : public Bird {
public:
    virtual void Fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void Eat()       override { std::cout << "Sparrow eating seeds...\n"; }
    void MakeSound() override { std::cout << "Tweet tweet!\n"; }
    void Fly()       override { std::cout << "Sparrow flying...\n"; }
};

class Eagle : public FlyingBird {
public:
    void Eat()       override { std::cout << "Eagle eating fish...\n"; }
    void MakeSound() override { std::cout << "Screech!\n"; }
    void Fly()       override { std::cout << "Eagle soaring high...\n"; }
};

// Ostrich is a Bird but NOT a FlyingBird — perfectly fine ✅
class Ostrich : public Bird {
public:
    void Eat()       override { std::cout << "Ostrich eating plants...\n"; }
    void MakeSound() override { std::cout << "Boom boom!\n"; }
    // No Fly() — no broken contracts
};

class BirdHandler {
public:
    void FeedBird(Bird& bird)             { bird.Eat(); }       // Works for ALL birds ✅
    void MakeFlyingBirdFly(FlyingBird& b) { b.Fly(); }          // Only called for flying birds ✅
};
