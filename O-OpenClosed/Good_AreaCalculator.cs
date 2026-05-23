// ✅ GOOD — Follows Open/Closed Principle
// The AreaCalculator never changes.
// To add a new shape, just CREATE a new class — no editing old code.

public abstract class Shape
{
    public abstract double Area();
}

public class Rectangle : Shape
{
    public double Width { get; set; }
    public double Height { get; set; }

    public override double Area() => Width * Height;
}

public class Circle : Shape
{
    public double Radius { get; set; }

    public override double Area() => Math.PI * Radius * Radius;
}

// ✅ New shape added WITHOUT touching any existing code
public class Triangle : Shape
{
    public double Base { get; set; }
    public double Height { get; set; }

    public override double Area() => 0.5 * Base * Height;
}

public class AreaCalculator
{
    // This method NEVER changes, no matter how many shapes you add
    public double Calculate(Shape shape) => shape.Area();
}

// Usage:
// var calc = new AreaCalculator();
// Console.WriteLine(calc.Calculate(new Rectangle { Width = 5, Height = 3 })); // 15
// Console.WriteLine(calc.Calculate(new Circle { Radius = 4 }));               // 50.26...
// Console.WriteLine(calc.Calculate(new Triangle { Base = 6, Height = 4 }));   // 12
