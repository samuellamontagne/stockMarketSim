//
// Created by hello on 2021-03-05.
//

#ifndef STOCKMARKETSIM_CUSTOMER_H
#define STOCKMARKETSIM_CUSTOMER_H
#include "Instruments.h"
#include "Bond.h"
#include <vector>
#define STARTING_CASH 10000;
#define MARKET_PERCENTAGE 0.1

class Customer {


private:
    double cash=STARTING_CASH; // start money
    double asset=STARTING_CASH;
    vector<Instruments*> instrumentsHoldList;  // hold vary  bond stock
    string name;
public:
    const string &getName() const;

    void setName(const string &name);

public:
    Customer(const string &name);
    const vector<Instruments *> &getInstrumentsHoldList() const;
    void setInstrumentsHoldList(const vector<Instruments *> &InstrumentsHoldList);
    double getProfit(const vector<struct Instruments *>& list) const;
    double getProfit(const vector<struct Instruments *>& list , const string &instrName) const;

    void PrintInfo(const vector<struct Instruments *>& list) const;

    void  sell(Instruments *instrument, double price, int quantity);

    void buy(Instruments *instrument, double price, int quantity);

    double getCash() const;

    void setCash(double inputCash);

    double calculateAsset(const vector<struct Instruments *>& list) const;

    static Instruments * creatClassByString(const string& str);

    vector<Bond*> bondsToBePaid(int n);
};


#endif
