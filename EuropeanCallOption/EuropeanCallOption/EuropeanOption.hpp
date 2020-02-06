//
//  EuropeanOption.hpp
//  EuropeanCallOption
//
//  Created by Dr Mahike on 04.02.20.
//  Copyright © 2020 Dr Mahike. All rights reserved.
//

#ifndef EuropeanOption_h
#define EuropeanOption_h
#include <string>
using namespace std;

#endif /* EuropeanOption_h */

class EuropeanOption {
    private:
        void init(); // Initialize all default values
        void copy(const EuropeanOption& o2);
        
        // kernel function for option calculations
        double CallPrice() const;
        double PutPrice() const;
        double CallDelta() const;
        double PutDelta() const;
    
    public:
        // The following data is public for convenience only
        double rate_of_interest;   // Interest rate
        double sigma;   // Volatility
        double strike_price;   // Strike Price
        double time;   //  Expiry date
        double stock_price;   //  Current underlying price
        double cost_of_cary;   // Cost of carry
        string optType;  // Option name, a call or put
    
    public:
        // Constructors
        EuropeanOption();   // Default call option
        EuropeanOption(const EuropeanOption& option2);  // Copy constructor
        EuropeanOption(const string& optionType);
    
        // Destructor
    virtual ~EuropeanOption();
    
    // Assignment operator
    EuropeanOption& operator = (const EuropeanOption& option2);
    
    // Functions that calculate option price and (some) sensitivites
    double Price() const;
    double Delta() const;
    
    // Modifier functions
    void toggle();  // Change option type, call or put
        
    
};
