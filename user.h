#ifndef USER_H
#define USER_H


#include <string>
#include <sstream>
#include <vector>
#include "portfolio.h"

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& email);
    std::string getUsername() const;
    std::string getPassword() const;
    std::string getEmail() const;
    
    void addPortfolio(const Portfolio& portfolio);
    const std::vector<Portfolio>& getPortfolios() const;
    Portfolio& createPortfolio();
    void viewPortfolios() const;
private:
    std::string username;
    std::string password;
    std::string email;
    std::vector<Portfolio> portfolios;

};

#endif