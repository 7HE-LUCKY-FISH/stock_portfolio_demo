#ifndef STOCK_H
#define STOCK_H


#include <string>

class Stock {
public:
    Stock();
    Stock(const std::string& symbol, const std::string& name,  double quantity, double price);
    
    std::string getSymbol() const;
    std::string getName() const;
    double getQuantity() const;
    double getPrice() const;
    void setPrice(double price);
    bool operator<(const Stock& other) const;

private:
    std::string symbol;
    std::string name;
    double quantity;
    double price;
};

#endif