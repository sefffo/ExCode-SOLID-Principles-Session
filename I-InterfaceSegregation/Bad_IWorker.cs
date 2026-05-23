// ❌ BAD — Violates Interface Segregation Principle
// The IWorker interface forces ALL workers to implement Eat().
// But robots don't eat! This forces an unnatural implementation.

public interface IWorker
{
    void Work();
    void Eat();  // ❌ Why should a Robot implement this?
}

public class HumanWorker : IWorker
{
    public void Work() => Console.WriteLine("Human working...");
    public void Eat()  => Console.WriteLine("Human eating lunch...");
}

public class RobotWorker : IWorker
{
    public void Work() => Console.WriteLine("Robot working...");

    // ❌ Forced to implement a method that makes no sense for a robot
    public void Eat() => throw new NotImplementedException("Robots don't eat!");
}
