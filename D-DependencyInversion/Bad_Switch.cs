// ❌ BAD — Violates Dependency Inversion Principle
// The high-level Switch class is DIRECTLY dependent on the low-level LightBulb class.
// Want to control a Fan or TV? You must edit the Switch class. ❌
// Unit testing Switch without a real LightBulb is impossible.

public class LightBulb
{
    public void TurnOn()  => Console.WriteLine("LightBulb is ON");
    public void TurnOff() => Console.WriteLine("LightBulb is OFF");
}

public class Switch
{
    // ❌ Hard-coded dependency on a concrete class
    private LightBulb _bulb = new LightBulb();

    public void Operate(bool on)
    {
        if (on) _bulb.TurnOn();
        else    _bulb.TurnOff();
    }
}

// To control a Fan, you'd have to change Switch:
// private Fan _fan = new Fan(); — modifying tested code ❌
