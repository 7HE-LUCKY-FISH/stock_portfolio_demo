#include "portfolio.h"
#include "user.h"
#include <iostream>
#include <exception>

int main() {
    try {
        //CSV are loaded into the file with symbol, name, price, quantity
        //Output file are also the same 
        /*
        You can either create protfolio using
        Portfolio* portfolio1 = new Portfolio();
        manually adds it to the user
        or
        Portfolio* portfolio1 = user.createPortfolio();
        (which automatically adds the portfolio to the user)
        */
        

        User user("john_doeeee", "password123", "john@example.com");
        Portfolio* portfolio1 = user.createPortfolio();
        Portfolio* portfolio2 = new Portfolio();
        Stock s1("NVDA", "Nvidia",10,125);
        portfolio1->addStock(s1);

        user.addPortfolio(portfolio2);

        
        portfolio1->loadFromFile("test.txt");
        portfolio2->loadFromFile("hashtest.txt");
        //sorts by quantity
        portfolio1->quickSort();
        //sort by price
        portfolio2->heapSort();


        //write portfolio to output file 
        portfolio1->saveToFile("output.txt");
        portfolio2->saveToFile("output2.txt");
        // View user's portfolios
        std::cout << "User: " << user.getUsername() << "\n";
        user.viewPortfolios();



    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
/*
User: john_doeeee
Portfolio 1:
  Stock Symbol: AMZN, Name: Amazon, Price: 3300.5, Quantity: 5
  Stock Symbol: GOOGL, Name: Alphabet, Price: 2900.1, Quantity: 7
  Stock Symbol: FB, Name: Meta, Price: 345, Quantity: 8
  Stock Symbol: NFLX, Name: Netflix, Price: 500, Quantity: 9
  Stock Symbol: NVDA, Name: Nvidia, Price: 125, Quantity: 10
  Stock Symbol: APPL, Name: Apple, Price: 200, Quantity: 10.4
  Stock Symbol: TSLA, Name: Tesla, Price: 650.2, Quantity: 12
  Stock Symbol: ORCL, Name: Oracle, Price: 90.15, Quantity: 14
  Stock Symbol: MSFT, Name: Microsoft, Price: 280, Quantity: 15
  Stock Symbol: INTC, Name: Intel, Price: 55.3, Quantity: 20
  Stock Symbol: WMT, Name: Walmart, Price: 85.12, Quantity: 23

Portfolio 2:
  Stock Symbol: INTC, Name: Intel Corporation, Price: 42.25, Quantity: 40
  Stock Symbol: WMT, Name: Walmart, Price: 58.35, Quantity: 25
  Stock Symbol: KO, Name: Coca-Cola, Price: 61.45, Quantity: 30
  Stock Symbol: DIS, Name: Walt Disney, Price: 112.9, Quantity: 22
  Stock Symbol: JNJ, Name: Johnson & Johnson, Price: 152.15, Quantity: 18
  Stock Symbol: AMD, Name: Advanced Micro Devices, Price: 152.7, Quantity: 15
  Stock Symbol: PG, Name: Procter & Gamble, Price: 162.8, Quantity: 10
  Stock Symbol: IBM, Name: International Business Machines, Price: 172.3, Quantity: 8
  Stock Symbol: TSLA, Name: Tesla, Price: 177.3, Quantity: 20
  Stock Symbol: AAPL, Name: Apple, Price: 185.25, Quantity: 15
  Stock Symbol: JPM, Name: JPMorgan Chase, Price: 192.75, Quantity: 12
  Stock Symbol: MSFT, Name: Microsoft, Price: 415.5, Quantity: 8
  Stock Symbol: META, Name: Meta Platforms, Price: 485.6, Quantity: 7
  Stock Symbol: NFLX, Name: Netflix, Price: 605.75, Quantity: 3
  Stock Symbol: NVDA, Name: NVIDIA, Price: 878.35, Quantity: 5

*/