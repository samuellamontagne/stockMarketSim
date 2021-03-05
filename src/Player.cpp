//
// Created by hello on 2021-03-05.
//

#include "Player.h"
#include "Stock.h"
#include <typeinfo>

double Player::getCash() const {
    return cash;
}

void Player::setCash(double cash) {
    Player::cash = cash;
}


void Player::buy(Instruments* instrument, double price, int volume) {
    if(price*volume <= cash) {
        cash-=price*volume;
        // on market side


        instrument->setQuantity(instrument->getQuantity()-volume);
        // on player side
         // has this object
        for (auto & i : playerAccount) {
            if(i->getName() == instrument->getName()){
                i->setQuantity(i->getQuantity()-volume);
                return;
            }
        }
        //no has this object
        string temp1=(typeid(*instrument).name());
        string result;
        for(char c : temp1){
            if( isalpha(c)){
                result+=tolower(c);
            }
        }
        Instruments* it =  creatClassByString(result);
        Instruments* tt =  &*instrument;

        it->setQuantity(volume);
        it->updatePrice(price);
        it->setName(instrument->getName());
        playerAccount.push_back(it);
    }else{
        cout << "not enough cash;" <<endl;
    }
}



void Player::sell(Instruments &instrument, double price, int volume) {
    for (int i =0 ;i < playerAccount.size();i++) {
        if(playerAccount.at(i)->getName() == instrument.getName() ){
            // if player have enough quantity player could sell
            if(playerAccount.at(i)->getQuantity() > volume){  // still have this object
                instrument.setQuantity(instrument.getQuantity()+volume);
                playerAccount.at(i)->setQuantity(playerAccount.at(i)->getQuantity()-volume);
                cash+=price*volume;
                break;
            } else if(playerAccount.at(i)->getQuantity() == volume){ // not have this stock
                playerAccount.erase(playerAccount.begin()+i);  // remove from playerAccount
                cash+=price*volume;
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

Instruments* Player::creatClassByString(string str) {
    if(str=="stock"){
        return new Stock("none",1.0,1);
    }else if(str== "bond"){
        return new Bond("none",1.0,1);
    }
}



