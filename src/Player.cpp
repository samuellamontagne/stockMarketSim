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

const vector <Instruments> &Player::getAcount() const {
    return playerAccount;
}

void Player::setAcount(const vector <Instruments> &acount) {
    Player::playerAccount = acount;
}

void Player::buy(Instruments* instrument, double price, int quantity) {
    if(price*quantity < cash) {
        instrument->setQuantity(instrument->getQuantity()-quantity);
        for (int i = 0; i < playerAccount.size(); ++i) {
            playerAccount
        }

        playerAccount.at(i).setQuantity(instrument.getQuantity()-quantity);
    }else{
        cout << "not enough cash;" <<endl;
        return false;
    }
}



void Player::sell(Instruments &instrument, double price, int quantity) {
    for (int i = 0; i < ; ++i) {
        if(playerAccount.at(i).getName() == instrument.getName() ){
            // if I have enough quantity I could sell
            if(playerAccount.at(i).getQuantity() >= quantity){
                instrument.setQuantity(instrument.getQuantity()+quantity);
                playerAccount.at(i).setQuantity(playerAccount.at(i).getQuantity()-quantity);
                break;
            } else {
                cout << " not enough quantity";
            }
        } else{
            cout << "You do not have " << instrument.getName() << endl;
        }
    }
}




