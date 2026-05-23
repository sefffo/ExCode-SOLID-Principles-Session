// ✅ GOOD — Follows Interface Segregation Principle
// Split the fat interface into smaller, focused ones.

#include <iostream>

// Every worker can work
class IWorkable {
public:
    virtual void Work() = 0;
    virtual ~IWorkable() = default;
};

// Only biological workers need to eat
class IEatable {
public:
    virtual void Eat() = 0;
    virtual ~IEatable() = default;
};

// Human implements BOTH interfaces
class HumanWorker : public IWorkable, public IEatable {
public:
    void Work() override { std::cout << "Human working...\n"; }
    void Eat()  override { std::cout << "Human eating lunch...\n"; }
};

// Robot only implements what it needs ✅
class RobotWorker : public IWorkable {
public:
    void Work() override { std::cout << "Robot working 24/7...\n"; }
    // No Eat() — no forced exception ✅
};

// Usage:
// HumanWorker h; RobotWorker r;
// h.Work(); h.Eat();
// r.Work(); // fine ✅
