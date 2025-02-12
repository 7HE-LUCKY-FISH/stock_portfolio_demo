#include "portfolio.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>

static inline std::string trim(const std::string& str) {
    const std::string whitespace = " \t";
    size_t start = str.find_first_not_of(whitespace);
    size_t end = str.find_last_not_of(whitespace);
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

Portfolio::Portfolio() : stockCount(0), capacity(10) {
    stocks = new Stock[capacity];
}

Portfolio::~Portfolio() {
    delete [] stocks;
}


Portfolio::Portfolio(const Portfolio& other)
    : stockCount(other.stockCount), capacity(other.capacity) {
    stocks = new Stock[capacity];
    for (int i = 0; i < stockCount; ++i) {
        stocks[i] = other.stocks[i];
    }
}

Portfolio& Portfolio::operator=(const Portfolio& other) {
    if (this != &other) {
        delete [] stocks;
        stockCount = other.stockCount;
        capacity = other.capacity;
        stocks = new Stock[capacity];
        for (int i = 0; i < stockCount; ++i) {
            stocks[i] = other.stocks[i];
        }
    }
    return *this;
}

void Portfolio::resize() {
    capacity *= 2;
    Stock* newStocks = new Stock[capacity];
    for (int i = 0; i < stockCount; ++i) {
        newStocks[i] = stocks[i];
    }
    delete [] stocks;
    stocks = newStocks;
}


void Portfolio::addStock(const Stock& stock) {
    if (stockCount == capacity) {
        resize();
    }
    stocks[stockCount++] = stock;
}



bool Portfolio::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Could not open file " + filename);
        //not sure if throwing the exception works well
    }
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string token;

        // Parse symbol
        std::getline(ss, token, ',');
        std::string symbol = trim(token);
        //Parse name
        std::getline(ss, token, ',');
        std::string name = trim(token);
        // Parse price
        std::getline(ss, token, ',');
        double price = std::stod(trim(token));
        
        // Parse amount (quantity)
        std::getline(ss, token, ',');
        double quantity = std::stod(trim(token));
        
        // Create stock with an empty name
        Stock stock(symbol, name, quantity, price);
        addStock(stock);
    }
    return true;
}
bool Portfolio:: saveToFile(const std::string& filename)const{
    std::ofstream file(filename);
    if (!file.is_open()){
        throw std:: invalid_argument("Could not open file" +filename);
    }
    for (int i = 0; i < stockCount; ++i) {
        file << stocks[i].getSymbol() << ","
             << stocks[i].getName() << ","
             << std::fixed << std::setprecision(2) << stocks[i].getPrice() << ","
             << stocks[i].getQuantity() << std::endl;
    }
    file.close();
    return true;
}


const Stock* Portfolio::getStocks() const {
    return stocks;
}

int Portfolio::getStockCount() const {
    return stockCount;
}