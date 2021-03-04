//
// Created by hello on 2021-03-05.
//

#include "Player.h"

int Player::getTotalMoney() const {
    return cash;
}

void Player::setTotalMoney(int totalMoney) {
    Player::cash = totalMoney;
}



void Player::buy(Instruments* instrument, double price, int quantity) {
    if(price*quantity < cash) {
        // on market side
        instrument->setQuantity(instrument->getQuantity()-quantity);
        // on player side
         // has this object
        for (auto & i : playerAccount) {
            if(i->getName() == instrument->getName()){
                i->setQuantity(i->getQuantity()-quantity);
                return;
            }
        }
        //no has this object
        Instruments* it;
        it->setQuantity(quantity);
        playerAccount.push_back(it);
    }else{
        cout << "not enough cash;" <<endl;
    }
}



void Player::sell(Instruments &instrument, double price, int quantity) {
    for (auto & i : playerAccount) {
        if(i->getName() == instrument.getName() ){
            // if I have enough quantity I could sell
            if(i->getQuantity() >= quantity){
                instrument.setQuantity(instrument.getQuantity()+quantity);
                i->setQuantity(i->getQuantity()-quantity);
                break;
            } else {
                cout << " not enough quantity";
            }
        } else{
            cout << "You do not have " << instrument.getName() << endl;
        }
    }
}

const vector<Instruments *> &Player::getPlayerAccount() const {
    return playerAccount;
}

void Player::setPlayerAccount(const vector<Instruments *> &playerAccount) {
    Player::playerAccount = playerAccount;
}




