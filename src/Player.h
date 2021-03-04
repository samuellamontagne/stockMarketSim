//
// Created by hello on 2021-03-05.
//

#ifndef STOCKMARKETSIM_PLAYER_H
#define STOCKMARKETSIM_PLAYER_H
#include "Instruments.h"
#include "Bond.h"
#include <vector>

class Player {
private:
    int cash=100; // start money
    vector<Instruments*> playerAccount;  // hold vary  bond stock
public:
    int getTotalMoney() const;

    const vector<Instruments *> &getPlayerAccount() const;

    void setPlayerAccount(const vector<Instruments *> &playerAccount);

    void setTotalMoney(int totalMoney);

    void  sell(Instruments &instrument, double price, int quantity);

    void buy(Instruments *instrument, double price, int quantity);
};


#endif
