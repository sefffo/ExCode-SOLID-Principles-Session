// ❌ BAD — Violates Single Responsibility Principle
// This class has THREE responsibilities:
// 1. Saving user to the database
// 2. Sending welcome emails
// 3. Logging
// If ANY of these needs to change, you have to touch this one class.

#include <iostream>
#include <string>

class UserService {
public:
    void RegisterUser(const std::string& username, const std::string& email) {
        // Responsibility 1: Save to DB
        std::cout << "Saving " << username << " to database...\n";

        // Responsibility 2: Send email
        std::cout << "Sending welcome email to " << email << "...\n";

        // Responsibility 3: Log
        std::cout << "Logging registration of " << username << "...\n";
    }
};
