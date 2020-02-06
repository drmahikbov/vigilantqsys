//
//  main.cpp
//  EuropeanCallOption
//
//  Created by Dr Mahike on 04.02.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#include <iostream>
#include "EuropeanOption.hpp"   // Declaration of functions
#include <math.h>   // For mathematical functions


// Calculated Normal Distribution function
double calculated_normal_distribution(double d) {
    // Wikipedia https://en.wikipedia.org/wiki/Normal_distribution#Cumulative_distribution_function
    // and some little alegbra gives the following
    return (1 - 0.5*erfc(d/sqrt(2)));
}

// Kernel functions
double EuropeanOption::CallPrice() const {
    // Black-Scholes formula
    double tmp = sigma * sqrt(time); // σ*t^(1/2)
    
    double d1 = ( log(stock_price / strike_price) + (cost_of_cary + (sigma * sigma)*0.5) * time) / tmp;
    double d2 = d1 - tmp;
    
    return (stock_price * exp((cost_of_cary - rate_of_interest) * time) * calculated_normal_distribution(d1)) - (strike_price * exp(-rate_of_interest * time) * calculated_normal_distribution(d2));
}

double EuropeanOption::PutPrice() const {
    // Black-Scholes formula
    double tmp = sigma * sqrt(time); // σ*t^(1/2)
    
    double d1 = ( log(stock_price/strike_price) + (cost_of_cary + (sigma*sigma)*0.5) * time)/ tmp;
    double d2 = d1 - tmp;
    
    return (strike_price*exp(-rate_of_interest * time)* calculated_normal_distribution(-d2)) - (stock_price * exp((cost_of_cary-rate_of_interest)*time) * calculated_normal_distribution(-d1));
}

double EuropeanOption::CallDelta() const {
    
    double tmp = sigma * sqrt(time);
    
    double d1 = ( log(stock_price/strike_price) + (cost_of_cary + (sigma*sigma)*0.5) * time)/ tmp;
    
    return exp((cost_of_cary-rate_of_interest)*time) * calculated_normal_distribution(d1);
}

double EuropeanOption::PutDelta() const {
    
    double tmp = sigma * sqrt(time);
    
    double d1 = ( log(stock_price/strike_price) + (cost_of_cary + (sigma*sigma)*0.5) * time)/ tmp;
    
    return exp((cost_of_cary-rate_of_interest)*time) * (calculated_normal_distribution(d1) - 1);
}

void EuropeanOption::init() {
    // Initialize all default values
    
    // Default values
    rate_of_interest = 0.08;
    sigma = 0.3;
    strike_price = 65.0;
    time = 0.25;
    stock_price = 60.0;
    cost_of_cary = rate_of_interest; // BSM model from 1973
    optType = "C"; // European Call Option
    
}

void EuropeanOption::copy(const EuropeanOption& o2) {
    rate_of_interest = o2.rate_of_interest;
    sigma = o2.sigma;
    strike_price = o2.strike_price;
    time = o2.time;
    stock_price = o2.stock_price;
    cost_of_cary = o2.cost_of_cary;
    
    optType = o2.optType;
    
}

EuropeanOption::EuropeanOption() {
    // Default call option
    init();
}

EuropeanOption::EuropeanOption(const string& optionType) {
    // Create option type
    
    init();
    optType = optionType;
    if (optionType == "c") {
        optType = "C";
    }
}

EuropeanOption::~EuropeanOption() {
    // Destructor
}

EuropeanOption& EuropeanOption::operator=(const EuropeanOption& option2) {
    // Assignment operator (deep copy)
    
    if(this == &option2) {
        return *this;
    }
        copy(option2);
        return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price() const {
    if (optType == "C") {
        return CallPrice();
    }
    else {
        return PutPrice();
    }
}

double EuropeanOption::Delta() const {
    if (optType == "C") {
        return CallDelta();
    } else {
        return PutDelta();
    }
}

// Modifier functions
void EuropeanOption::toggle() {
    // Change option type
    if (optType == "C") {
        optType = "P";
    } else {
        optType = "C";
    }
}

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
