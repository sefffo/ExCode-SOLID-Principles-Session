// ❌ BAD — Violates Dependency Inversion Principle
// The high-level Switch class is DIRECTLY dependent on the low-level LightBulb class.
// Want to control a Fan or TV? You must edit the Switch class. ❌

#include <iostream>

class LightBulb {
public:
    void TurnOn()  { std::cout << "LightBulb is ON\n"; }
    void TurnOff() { std::cout << "LightBulb is OFF\n"; }
};

class Switch {
    // ❌ Hard-coded dependency on a concrete class
    LightBulb _bulb;

public:
    void Operate(bool on) {
        if (on) _bulb.TurnOn();
        else    _bulb.TurnOff();
    }
};

// To control a Fan, you'd have to change Switch — modifying tested code ❌
