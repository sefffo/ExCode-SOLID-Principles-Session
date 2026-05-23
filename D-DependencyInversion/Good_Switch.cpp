// ✅ GOOD — Follows Dependency Inversion Principle
// Both Switch (high-level) and LightBulb/Fan (low-level) depend on ISwitchable (abstraction).
// Switch doesn't care WHAT it controls — just that it implements ISwitchable.

#include <iostream>
#include <memory>

// The abstraction both sides depend on
class ISwitchable {
public:
    virtual void TurnOn()  = 0;
    virtual void TurnOff() = 0;
    virtual ~ISwitchable() = default;
};

// Low-level class 1
class LightBulb : public ISwitchable {
public:
    void TurnOn()  override { std::cout << "LightBulb is ON ✅\n"; }
    void TurnOff() override { std::cout << "LightBulb is OFF\n"; }
};

// Low-level class 2 — added WITHOUT touching Switch
class Fan : public ISwitchable {
public:
    void TurnOn()  override { std::cout << "Fan is ON ✅\n"; }
    void TurnOff() override { std::cout << "Fan is OFF\n"; }
};

// Low-level class 3 — still no changes to Switch needed
class SmartTV : public ISwitchable {
public:
    void TurnOn()  override { std::cout << "SmartTV is ON ✅\n"; }
    void TurnOff() override { std::cout << "SmartTV is OFF\n"; }
};

// High-level class depends ONLY on the abstraction ✅
class Switch {
    std::shared_ptr<ISwitchable> _device;

public:
    explicit Switch(std::shared_ptr<ISwitchable> device) : _device(device) {}

    void Operate(bool on) {
        if (on) _device->TurnOn();
        else    _device->TurnOff();
    }
};

// Usage:
// auto s1 = Switch(std::make_shared<LightBulb>());
// auto s2 = Switch(std::make_shared<Fan>());
// s1.Operate(true);   // LightBulb is ON ✅
// s2.Operate(false);  // Fan is OFF
