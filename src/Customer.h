//
// Created by hello on 2021-03-05.
//

#ifndef STOCKMARKETSIM_CUSTOMER_H
#define STOCKMARKETSIM_CUSTOMER_H
#include "Instruments.h"
#include "Bond.h"
#include <vector>
#define STARTING_CASH 10000;
class Customer {


private:
    double cash=STARTING_CASH; // start money
    double asset=STARTING_CASH;
    vector<Instruments*> customerAccount;  // hold vary  bond stock
public:
    const vector<Instruments *> &getCustomerAccount() const;
    void setCustomerAccount(const vector<Instruments *> &customerAccount);
    double getProfile(const vector<struct Instruments *>& list) const;


    void  sell(Instruments &instrument, double price, int quantity);

    void buy(Instruments *instrument, double price, int quantity);

    double getCash() const;

    void setCash(double cash);

    double calculateAsset(const vector<struct Instruments *>& list) const;

    static Instruments * creatClassByString(const string& str);
};


#endif
