// ✅ GOOD — Follows Single Responsibility Principle
// Each class now has exactly ONE reason to change.

#include <iostream>
#include <string>
#include <memory>

// Responsibility 1: Only handles database operations
class UserRepository {
public:
    void Save(const std::string& username) {
        std::cout << "Saving " << username << " to database...\n";
    }
};

// Responsibility 2: Only handles email sending
class EmailService {
public:
    void SendWelcomeEmail(const std::string& email) {
        std::cout << "Sending welcome email to " << email << "...\n";
    }
};

// Responsibility 3: Only handles logging
class Logger {
public:
    void Log(const std::string& message) {
        std::cout << "LOG: " << message << "\n";
    }
};

// Orchestrator: only coordinates the above services
class UserService {
    UserRepository _repo;
    EmailService   _email;
    Logger         _logger;

public:
    void RegisterUser(const std::string& username, const std::string& email) {
        _repo.Save(username);
        _email.SendWelcomeEmail(email);
        _logger.Log("User " + username + " registered.");
    }
};

// 💡 Now if the email provider changes, only EmailService changes.
// The registration logic and DB logic are completely untouched.
