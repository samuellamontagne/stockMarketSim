//
// Created by hello on 2021-03-05.
//

#ifndef STOCKMARKETSIM_PLAYER_H
#define STOCKMARKETSIM_PLAYER_H
#include "Instruments.h"
#include <vector>

class Player {
private:
    int cash=100; // start money
    vector<Instruments> playerAccount;  // hold vary  bond stock
public:
    int getTotalMoney() const;

    void setTotalMoney(int totalMoney);

    const vector <Instruments> &getAcount() const;

    void setAcount(const vector <Instruments> &acount);


    void  sell(Instruments &instrument, double price, int quantity);


    void buy(Instruments *instrument, double price, int quantity);
};


#endif
