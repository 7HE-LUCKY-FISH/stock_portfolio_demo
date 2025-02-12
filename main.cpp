#include "portfolio.h"
#include "user.h"
#include <iostream>
#include <exception>

int main() {
    try {
        
        //CSV are loaded into the file with symbol, name, price, quantity
        //Output file are also the same 
        
        // Create a user and add the portfolio to the user
        User user("john_doeeee", "password123", "john@example.com");
        Portfolio& portfolio1 = user.createPortfolio();
        // Load a portfolio from a file
        portfolio1.loadFromFile("test.txt");
        //create new stock and add it to portfolio
        Stock s1("NVDA", "Nvidia",10,125);
        portfolio1.addStock(s1);

        portfolio1.selectionSort();
        //write portfolio to output file
        portfolio1.saveToFile("output.txt");
        // View user's portfolios
        std::cout << "User: " << user.getUsername() << "\n";
        user.viewPortfolios();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}