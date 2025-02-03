#include <string>
#include <sstream>
#include <vector>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& email);
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;

    static User fromTextLine(const std::string& line);

private:
    std::string username;
    std::string password;
    std::string email;

};