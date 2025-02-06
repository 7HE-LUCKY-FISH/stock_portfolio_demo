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