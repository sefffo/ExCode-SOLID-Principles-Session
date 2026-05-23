// ✅ GOOD — Follows Single Responsibility Principle
// Each class now has exactly ONE reason to change.

// Responsibility 1: Only handles database operations
public class UserRepository
{
    public void Save(string username)
        => Console.WriteLine($"Saving {username} to database...");
}

// Responsibility 2: Only handles email sending
public class EmailService
{
    public void SendWelcomeEmail(string email)
        => Console.WriteLine($"Sending welcome email to {email}...");
}

// Responsibility 3: Only handles logging
public class Logger
{
    public void Log(string message)
        => Console.WriteLine($"LOG: {message}");
}

// Orchestrator: only coordinates the above services
public class UserService
{
    private readonly UserRepository _repo = new();
    private readonly EmailService _email = new();
    private readonly Logger _logger = new();

    public void RegisterUser(string username, string email)
    {
        _repo.Save(username);
        _email.SendWelcomeEmail(email);
        _logger.Log($"User {username} registered.");
    }
}

// 💡 Now if the email provider changes, only EmailService changes.
// The registration logic and DB logic are completely untouched.
