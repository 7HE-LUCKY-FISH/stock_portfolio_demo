#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "stock.h"
#include <vector>
#include <string>

class Portfolio {
public:
    Portfolio();
    ~Portfolio();
    Portfolio(const Portfolio& other);
    Portfolio& operator=(const Portfolio& other);

    void addStock(const Stock& stock);
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std:: string& filename) const;

    const Stock* getStocks() const;
    int getStockCount() const;

    void selectionSort();
    //void insertionSort();
    //void quickSort();
private:
    Stock* stocks;
    int stockCount;
    int capacity;
    void resize();
};

#endif