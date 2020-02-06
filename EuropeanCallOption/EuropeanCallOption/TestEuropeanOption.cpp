//
//  TestEuropeanOption.cpp
//  EuropeanCallOption
//
//  Created by Dr Mahike on 06.02.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <stdio.h>
#include "EuropeanOption.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    // All options are European
    
    // Call option on a stock
    EuropeanOption callOption;
    cout << "Call option on a stock: " << callOption.Price() << endl;
    
    // Put option on a stock index
    EuropeanOption indexOption;
    indexOption.optType = "P";
    indexOption.stock_price = 100;
    indexOption.strike_price = 95;
    indexOption.time = 0.50;
    indexOption.rate_of_interest = 0.10;
    indexOption.sigma = 0.20;
    double dividend_yield = 0.05;
    indexOption.cost_of_cary = indexOption.rate_of_interest - dividend_yield;
    
    cout << "Put option on index: " << indexOption.Price() << endl;
    
    // Call and Put as a future
    EuropeanOption futureOption;
    futureOption.optType = "P";
    futureOption.stock_price = 19.0;
    futureOption.strike_price = 19.0;
    futureOption.time = 0.75;
    futureOption.rate_of_interest = 0.10;
    futureOption.sigma = 0.28;
    futureOption.cost_of_cary = 0.0;
    
    cout << "Put option on future: " << futureOption.Price() << endl;
    
    // Now change over to call the option
    futureOption.toggle();
    cout << "Call option on future: " << futureOption.Price() << endl;
    
    return 0;
}
