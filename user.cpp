#include <string>
#include <iostream>
#include "user.h"


User::User(const std::string& username, const std::string& password, const std::string& email)
    : username(username), password(password), email(email) {}

User::~User() {
    for (Portfolio* portfolio : portfolios) {
        delete portfolio;
    }
    portfolios.clear();
}

std::string User::getUsername() const{
    return username;
}

std::string User::getPassword() const{
    return password;
}

std::string User::getEmail() const{
    return email;
}

void User::addPortfolio(Portfolio* portfolio) {
    portfolios.push_back(portfolio);
}

Portfolio* User::createPortfolio() {
    Portfolio* newPortfolio = new Portfolio();
    portfolios.push_back(newPortfolio);
    return newPortfolio;
}


const std::vector<Portfolio*>& User::getPortfolios() const {
    return portfolios;
}


void User::viewPortfolios() const {
    if (portfolios.empty()) {
        std::cout << "No portfolios available.\n";
        return;
    }

    for (size_t i = 0; i < portfolios.size(); ++i) {
        std::cout << "Portfolio " << i + 1 << ":\n";
        int count = portfolios[i]->getStockCount();
        if (count == 0) {
            std::cout << "  No stocks in this portfolio.\n";
        } else {
            const Stock* stocks = portfolios[i]->getStocks();
            for (int j = 0; j < count; ++j) {
                std::cout << "  Stock Symbol: " << stocks[j].getSymbol()
                          << ", Name: " << stocks[j].getName()
                          << ", Price: " << stocks[j].getPrice()
                          << ", Quantity: " << stocks[j].getQuantity() << "\n";
            }
        }
        std::cout << "\n";
    }
}