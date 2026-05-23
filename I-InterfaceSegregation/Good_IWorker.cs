// ✅ GOOD — Follows Interface Segregation Principle
// Split the fat interface into smaller, focused ones.
// Each class only implements what it actually needs.

// Every worker can work
public interface IWorkable
{
    void Work();
}

// Only biological workers need to eat
public interface IEatable
{
    void Eat();
}

// Optional: a base marker if needed
public interface IWorker : IWorkable { }

// Human implements BOTH interfaces
public class HumanWorker : IWorkable, IEatable
{
    public void Work() => Console.WriteLine("Human working...");
    public void Eat()  => Console.WriteLine("Human eating lunch...");
}

// Robot only implements what it needs ✅
public class RobotWorker : IWorkable
{
    public void Work() => Console.WriteLine("Robot working 24/7...");
    // No Eat() — no forced NotImplementedException ✅
}

// Usage:
// IWorkable[] workers = { new HumanWorker(), new RobotWorker() };
// foreach (var w in workers) w.Work(); // Both work fine ✅
