#include <string>
#include <iostream>
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

void User::addPortfolio(const Portfolio& portfolio) {
    portfolios.push_back(portfolio);
}

Portfolio& User::createPortfolio() {
    portfolios.emplace_back();
    return portfolios.back();
}


const std::vector<Portfolio>& User::getPortfolios() const {
    return portfolios;
}


void User::viewPortfolios() const {
    if (portfolios.empty()) {
        std::cout << "No portfolios available.\n";
        return;
    }

    for (size_t i = 0; i < portfolios.size(); ++i) {
        std::cout << "Portfolio " << i + 1 << ":\n";
        const auto& stocks = portfolios[i].getStocks();
        if (stocks.empty()) {
            std::cout << "  No stocks in this portfolio.\n";
        } else {
            for (const auto& stock : stocks) {
                // Assumes Stock class has the respective getter methods
                std::cout << "  Stock Symbol: " << stock.getSymbol()
                          << ", Name: " << stock.getName()
                          << ", Price: " << stock.getPrice()
                          << ", Quantity: " << stock.getQuantity() << "\n";
            }
        }
        std::cout << "\n";
    }
}