#include "portfolio.h"
#include "user.h"
#include <iostream>
#include <exception>

int main() {
    try {
        // Load a portfolio from a file
        //I want to be able to create it without having to declare them seperately but i do not know
    
        // Create a user and add the portfolio to the user
        User user("john_doeeee", "password123", "john@example.com");
        Portfolio& portfolio1 = user.createPortfolio();
        portfolio1.loadFromFile("test.txt");
        // View user's portfolios
        std::cout << "User: " << user.getUsername() << "\n";
        user.viewPortfolios();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}