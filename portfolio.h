#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <vector>
#include <string>

class Portfolio {
public:
    void addStock(const Stock& stock);
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std:: string& filename) const;
    const std::vector<Stock>& getStocks() const;
private:
    std::vector<Stock> stocks;
};

#endif