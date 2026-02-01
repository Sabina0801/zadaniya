#include <iostream>
#include <vector>
#include <string>

class User {
public:
    std::string name;
    std::string email;
    std::string role;

    User(std::string n, std::string e, std::string r) 
        : name(n), email(e), role(r) {} [cite: 9]
};

class UserManager {
private:
    std::vector<User> users; [cite: 10]

    User* findUserByEmail(const std::string& email) {
        for (auto& user : users) {
            if (user.email == email) {
                return &user;
            }
        }
        return nullptr;
    } [cite: 22, 23, 28]

public:
    void AddUser(const User& user) {
        users.push_back(user);
    } [cite: 11, 26]

    void RemoveUser(const std::string& email) {
        for (auto it = users.begin(); it != users.end(); ++it) {
            if (it->email == email) {
                users.erase(it);
                break;
            }
        }
    } [cite: 11, 27]

    void UpdateUser(const std::string& email, const std::string& newName, const std::string& newRole) {
        User* user = findUserByEmail(email);
        if (user) {
            user->name = newName;
            user->role = newRole;
        }
    } [cite: 11, 24]
};

int main() {
    UserManager manager;
    manager.AddUser(User("Admin", "admin@company.com", "Admin"));
    return 0;
}
