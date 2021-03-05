//
// Created by hello on 2021-03-05.
//

#include "Customer.h"
#include "Stock.h"
#include <typeinfo>

double Customer::getCash() const {
    return cash;
}

void Customer::setCash(double cash) {
    Customer::cash = cash;
}


void Customer::buy(Instruments* instrument, double price, int volume) {
    if(price*volume <= cash) {
        cash-=price*volume;
        // on market side


        instrument->setQuantity(instrument->getQuantity()-volume);
        // on customer side
         // has this object
        for (auto & i : customerAccount) {
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
        it->setQuantity(volume);
        it->updatePrice(price);
        it->setName(instrument->getName());
        customerAccount.push_back(it);
    }else{
        cout << "not enough cash;" <<endl;
    }
}



void Customer::sell(Instruments &instrument, double price, int volume) {
    for (int i =0 ;i < customerAccount.size();i++) {
        if(customerAccount.at(i)->getName() == instrument.getName() ){
            // if customer have enough quantity customer could sell
            if(customerAccount.at(i)->getQuantity() > volume){  // still have this object
                instrument.setQuantity(instrument.getQuantity()+volume);
                customerAccount.at(i)->setQuantity(customerAccount.at(i)->getQuantity()-volume);
                cash+=price*volume;
                break;
            } else if(customerAccount.at(i)->getQuantity() == volume){ // not have this stock
                customerAccount.erase(customerAccount.begin()+i);  // remove from customerAccount
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

const vector<Instruments *> &Customer::getcustomerAccount() const {
    return customerAccount;
}

void Customer::setcustomerAccount(const vector<Instruments *> &list) {
    Customer::customerAccount = list;
}

double Customer::calculateAsset(const vector<struct Instruments *> list) const {
    if(customerAccount.empty()){
        return cash;
    }else{
        double subtotal=0;
        for (auto i : customerAccount) {
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



double Customer::getProfile(const vector<struct Instruments *> list) const {
    if(customerAccount.empty()){
       return cash-STARTING_CASH;
    }else{
      return  calculateAsset(list)-STARTING_CASH;
    }

}

Instruments* Customer::creatClassByString(string str) {
    if(str=="stock"){
        return new Stock("none",1.0,1);
    }else if(str== "bond"){
        return new Bond("none",1.0,1);
    }
}



