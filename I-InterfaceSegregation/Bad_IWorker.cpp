// ❌ BAD — Violates Interface Segregation Principle
// The IWorker interface forces ALL workers to implement Eat().
// But robots don't eat! This forces an unnatural implementation.

#include <iostream>
#include <stdexcept>

class IWorker {
public:
    virtual void Work() = 0;
    virtual void Eat()  = 0; // ❌ Why should a Robot implement this?
    virtual ~IWorker() = default;
};

class HumanWorker : public IWorker {
public:
    void Work() override { std::cout << "Human working...\n"; }
    void Eat()  override { std::cout << "Human eating lunch...\n"; }
};

class RobotWorker : public IWorker {
public:
    void Work() override { std::cout << "Robot working...\n"; }

    // ❌ Forced to implement a method that makes no sense for a robot
    void Eat() override { throw std::logic_error("Robots don't eat!"); }
};
