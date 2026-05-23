// ❌ BAD — Violates Open/Closed Principle
// Every time you add a new shape, you have to EDIT this method.
// What happens when you add Triangle, Hexagon, Pentagon...?
// You keep modifying tested code and risk breaking it.

public class Rectangle
{
    public double Width { get; set; }
    public double Height { get; set; }
}

public class Circle
{
    public double Radius { get; set; }
}

public class AreaCalculator
{
    public double Calculate(object shape)
    {
        if (shape is Rectangle r)
            return r.Width * r.Height;
        else if (shape is Circle c)
            return Math.PI * c.Radius * c.Radius;
        // ❌ Adding Triangle means editing this method again
        return 0;
    }
}
