// ❌ BAD — Violates Liskov Substitution Principle
// Ostrich IS-A Bird in the real world, but it BREAKS the Bird contract in code.
// If someone passes an Ostrich where a Bird is expected, the app CRASHES.

public class Bird
{
    public virtual void Fly()
        => Console.WriteLine("Bird is flying...");
}

public class Sparrow : Bird
{
    public override void Fly()
        => Console.WriteLine("Sparrow is flying...");
}

public class Ostrich : Bird
{
    public override void Fly()
        // ❌ This throws an exception — breaks the parent's contract!
        => throw new Exception("Ostriches can't fly!");
}

// This method EXPECTS any Bird to be able to fly.
// But if bird is Ostrich, it crashes at runtime. ❌
public class BirdHandler
{
    public void MakeBirdFly(Bird bird)
        => bird.Fly(); // 💥 CRASH if bird is Ostrich
}
