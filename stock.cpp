#include "stock.h"
#include <sstream>
#include <algorithm>

Stock::Stock(const std::string& symbol, const std::string& name, double quantity, double price)
    : symbol(symbol), name(name), quantity(quantity), price(price) {}

std::string Stock::getSymbol() const {
    return symbol;
}

std::string Stock::getName() const {
    return name;
}

double Stock::getQuantity() const {
    return quantity;
}

double Stock::getPrice() const {
    return price;
}

void Stock::setPrice(double price) {
    this->price = price;
}
//needs to be moved to porfolio class
static inline std::string trim(const std::string& str) {
    const std::string whitespace = " \t";
    size_t start = str.find_first_not_of(whitespace);
    size_t end = str.find_last_not_of(whitespace);
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

Stock Stock::fromTextLine(const std::string& line) {
    std::istringstream ss(line);
    std::string token;

    // Parse symbol
    std::getline(ss, token, ',');
    std::string symbol = trim(token);
    
    // Parse name
    std::getline(ss, token, ',');
    std::string name = trim(token);
    
    // Parse quantity
    std::getline(ss, token, ',');
    int quantity = std::stoi(trim(token));
    
    // Parse price
    std::getline(ss, token, ',');
    double price = std::stod(trim(token));
    
    return Stock(symbol, name, quantity, price);
}