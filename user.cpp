#include <string>

#include "user.h"


User::User(const std::string& username, const std::string& password, const std::string& email)
    : username(username), password(password), email(email) {}

std::string User::getUsername() const{
    return username;
}

std::string User::getPassword() const{
    return password;
}

std::string User::getEmail() const{
    return email;
}
