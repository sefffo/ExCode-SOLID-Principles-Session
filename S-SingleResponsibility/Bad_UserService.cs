// ❌ BAD — Violates Single Responsibility Principle
// This class has THREE responsibilities:
// 1. Saving user to the database
// 2. Sending welcome emails
// 3. Logging
// If ANY of these needs to change, you have to touch this one class.

public class UserService
{
    public void RegisterUser(string username, string email)
    {
        // Responsibility 1: Save to DB
        Console.WriteLine($"Saving {username} to database...");

        // Responsibility 2: Send email
        Console.WriteLine($"Sending welcome email to {email}...");

        // Responsibility 3: Log
        Console.WriteLine($"Logging registration of {username}...");
    }
}
