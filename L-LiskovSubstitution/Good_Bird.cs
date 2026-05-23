// ✅ GOOD — Follows Liskov Substitution Principle
// We model the hierarchy based on BEHAVIOR, not just real-world categories.
// FlyingBird and NonFlyingBird both substitute Bird safely.

// Base class: all birds share these behaviors
public abstract class Bird
{
    public abstract void Eat();
    public abstract void MakeSound();
}

// Only birds that CAN fly extend this
public abstract class FlyingBird : Bird
{
    public abstract void Fly();
}

public class Sparrow : FlyingBird
{
    public override void Eat()       => Console.WriteLine("Sparrow eating seeds...");
    public override void MakeSound() => Console.WriteLine("Tweet tweet!");
    public override void Fly()       => Console.WriteLine("Sparrow flying...");
}

public class Eagle : FlyingBird
{
    public override void Eat()       => Console.WriteLine("Eagle eating fish...");
    public override void MakeSound() => Console.WriteLine("Screech!");
    public override void Fly()       => Console.WriteLine("Eagle soaring high...");
}

// Ostrich is a Bird but NOT a FlyingBird — and that's perfectly fine ✅
public class Ostrich : Bird
{
    public override void Eat()       => Console.WriteLine("Ostrich eating plants...");
    public override void MakeSound() => Console.WriteLine("Boom boom!");
    // No Fly() method — no broken contracts
}

// Now each substitution is safe:
public class BirdHandler
{
    public void FeedBird(Bird bird)         => bird.Eat();       // Works for ALL birds ✅
    public void MakeFlyingBirdFly(FlyingBird b) => b.Fly();     // Only called for flying birds ✅
}
