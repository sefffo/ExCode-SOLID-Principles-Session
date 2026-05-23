// ✅ GOOD — Follows Dependency Inversion Principle
// Both Switch (high-level) and LightBulb/Fan (low-level) depend on ISwitchable (abstraction).
// Switch doesn't care WHAT it controls — just that it implements ISwitchable.

// The abstraction both sides depend on
public interface ISwitchable
{
    void TurnOn();
    void TurnOff();
}

// Low-level class 1
public class LightBulb : ISwitchable
{
    public void TurnOn()  => Console.WriteLine("LightBulb is ON ✅");
    public void TurnOff() => Console.WriteLine("LightBulb is OFF");
}

// Low-level class 2 — added WITHOUT touching Switch
public class Fan : ISwitchable
{
    public void TurnOn()  => Console.WriteLine("Fan is ON ✅");
    public void TurnOff() => Console.WriteLine("Fan is OFF");
}

// Low-level class 3 — still no changes to Switch needed
public class SmartTV : ISwitchable
{
    public void TurnOn()  => Console.WriteLine("SmartTV is ON ✅");
    public void TurnOff() => Console.WriteLine("SmartTV is OFF");
}

// High-level class — depends on abstraction, not concrete types
public class Switch
{
    private readonly ISwitchable _device;

    // ✅ Dependency is INJECTED — this is how ASP.NET Core DI works!
    public Switch(ISwitchable device)
        => _device = device;

    public void Operate(bool on)
    {
        if (on) _device.TurnOn();
        else    _device.TurnOff();
    }
}

// Usage — swap devices with zero changes to Switch:
// var lightSwitch = new Switch(new LightBulb());
// var fanSwitch   = new Switch(new Fan());
// var tvSwitch    = new Switch(new SmartTV());
//
// lightSwitch.Operate(true);  // LightBulb is ON ✅
// fanSwitch.Operate(true);    // Fan is ON ✅
// tvSwitch.Operate(false);    // SmartTV is OFF
//
// 💡 This is EXACTLY how ASP.NET Core registers services:
// builder.Services.AddScoped<ISwitchable, LightBulb>();
