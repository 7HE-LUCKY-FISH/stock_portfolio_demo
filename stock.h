#include <string>

class Stock {
public:
    Stock(const std::string& symbol, const std::string& name,  double quantity, double price);
    
    std::string getSymbol() const;
    std::string getName() const;
    double getQuantity() const;
    double getPrice() const;

    void setPrice(double price);

    //needs to be moved to porfolio class
    static Stock fromTextLine(const std::string& line);

private:
    std::string symbol;
    std::string name;
    double quantity;
    double price;

};