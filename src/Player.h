//
// Created by hello on 2021-03-05.
//

#ifndef STOCKMARKETSIM_PLAYER_H
#define STOCKMARKETSIM_PLAYER_H
#include "Instruments.h"
#include "Bond.h"
#include <vector>
#define STARTING_CASH 10000;

class Player {


private:
    double cash=STARTING_CASH; // start money
    double asset=STARTING_CASH;
    vector<Instruments*> playerAccount;  // hold vary  bond stock
public:
    const vector<Instruments *> &getPlayerAccount() const;
    void setPlayerAccount(const vector<Instruments *> &playerAccount);
    double getProfile(vector<struct Instruments *> list) const;


    void  sell(Instruments &instrument, double price, int quantity);

    void buy(Instruments *instrument, double price, int quantity);

    double getCash() const;

    void setCash(double cash);

    static double getCurrentPrice(Instruments *instrument);

    double calculateAsset(vector<struct Instruments *> list) const;
};


#endif
