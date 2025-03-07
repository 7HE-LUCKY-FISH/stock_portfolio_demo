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

void Portfolio::selectionSort() {
    for (int i = 0; i < stockCount - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < stockCount; ++j) {
            if (stocks[j] < stocks[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            Stock temp = stocks[i];
            stocks[i] = stocks[minIndex];
            stocks[minIndex] = temp;
        }
    }
}

void Portfolio::insertionSort(){
    for (int i = 1; i < stockCount; ++i) {
        Stock key = stocks[i];
        int j = i - 1;
        while (j >= 0 && key.getName()<stocks[j].getName()) {
            stocks[j + 1] = stocks[j];
            j = j - 1;
        }
        stocks[j + 1] = key;
    }
}

void Portfolio::quickSort() {
    if (stockCount <= 1) return;
    quickSort(0, stockCount - 1);
}

void Portfolio::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

int Portfolio::partition(int low, int high) {
    Stock pivot = stocks[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; ++j) {
        if (stocks[j].getQuantity() < pivot.getQuantity()) {
            ++i;
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return (i + 1);
}

void Portfolio::swap(int i, int j) {
    Stock temp = stocks[i];
    stocks[i] = stocks[j];
    stocks[j] = temp;
}



void Portfolio::heapify(Stock arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left].getPrice() > arr[largest].getPrice()){
        largest = left;
    }
    /*
    if (left < && arr[left].getName() > arr[largest].getName()){
        largest = left;
    }
    */

    if(right < n && arr[right].getPrice() > arr[largest].getPrice()){
        largest = right;
    }
    if(largest != i){
        swap(i, largest);
        heapify(arr, n, largest);
    }
}


void Portfolio::heapSort(){
    for(int i = stockCount/2 - 1; i >= 0; i--){
        heapify(stocks, stockCount, i);
    }
    //min heap
    for(int i = stockCount - 1; i >= 0; i--){
        swap(0, i);
        heapify(stocks, i, 0);
    }
    
}



