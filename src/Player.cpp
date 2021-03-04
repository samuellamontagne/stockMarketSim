//
// Created by hello on 2021-03-05.
//

#include "Player.h"


double Player::getCash() const {
    return cash;
}

void Player::setCash(double cash) {
    Player::cash = cash;
}


void Player::buy(Instruments* instrument, double price, int quantity) {
    if(price*quantity <= cash) {
        cash-=price*quantity;
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
        Instruments* it = instrument;
        it->setQuantity(quantity);
        it->updatePrice(price);
        playerAccount.push_back(it);
    }else{
        cout << "not enough cash;" <<endl;
    }
}



void Player::sell(Instruments &instrument, double price, int quantity) {
    for (int i =0 ;i < playerAccount.size();i++) {
        if(playerAccount.at(i)->getName() == instrument.getName() ){
            // if player have enough quantity player could sell
            if(playerAccount.at(i)->getQuantity() > quantity){  // still have this object
                instrument.setQuantity(instrument.getQuantity()+quantity);
                playerAccount.at(i)->setQuantity(playerAccount.at(i)->getQuantity()-quantity);
                cash+=price*quantity;
                break;
            } else if(playerAccount.at(i)->getQuantity() == quantity){ // not have this stock
                playerAccount.erase(playerAccount.begin()+i);  // remove from playerAccount
                cash+=price*quantity;
                break;
            }
            else {
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

void Player::setPlayerAccount(const vector<Instruments *> &list) {
    Player::playerAccount = list;
}

double Player::calculateAsset(const vector<struct Instruments *> list) const {
    if(playerAccount.empty()){
        return cash;
    }else{
        double subtotal=0;
        for (auto i : playerAccount) {
            for (auto j : list) {
                if(i->getName()==j->getName()){
                    subtotal+=i->getQuantity()*j->getPrice();
                    break;
                }
            }

        }
        return cash+subtotal;
    }
}



double Player::getProfile(const vector<struct Instruments *> list) const {
    if(playerAccount.empty()){
       return cash-STARTING_CASH;
    }else{
      return  calculateAsset(list)-STARTING_CASH;
    }

}





