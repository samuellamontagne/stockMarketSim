//
// Created by hello on 2021-03-05.
//

#include "Customer.h"
#include "Stock.h"
#include <typeinfo>
#include <iomanip>

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
        string className;
        for(char c : temp1){
            if( isalpha(c)){
                className+=tolower(c);
            }
        }
        Instruments* it =  creatClassByString(className);
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

const vector<Instruments *> &Customer::getCustomerAccount() const {
    return customerAccount;
}

void Customer::setCustomerAccount(const vector<Instruments *> &list) {
    Customer::customerAccount = list;
}

double Customer::calculateAsset(const vector<struct Instruments *>& list) const {
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



double Customer::getProfit(const vector<struct Instruments *>& list) const {
    if(customerAccount.empty()){
       return cash-STARTING_CASH;
    }else{
      return  calculateAsset(list)-STARTING_CASH;
    }
}


double Customer::getProfit(const vector<struct Instruments *>& list , const string &instrName) const {

    if(customerAccount.empty()){
        return 0;
    }else{
        for(auto i :customerAccount){
           if(i->getName() ==instrName){
               for(auto j :list){
                   if(j->getName() ==instrName){
                       return  (j->getPrice()-i->getPrice())*i->getQuantity();
                   }
               }
           }
        }
        return  0;
    }
}


Instruments* Customer::creatClassByString(const string& className) {
    if(className=="stock"){
        return new Stock("none",1.0,1);
    }else if(className== "bond"){
        return new Bond("none",1.0,1);
    }
}

void Customer::PrintInfo(const vector<struct Instruments *>& list) const {
    cout << "Customer: " << name << endl;
    cout << fixed << std::setprecision(2);
    cout << "cash: \t$" << cash << endl << "asset: \t$" << asset <<endl<< "profit: $" << getProfit(list) <<endl;
    cout << "Name\t"  <<  "cost($)\t\t" <<  "value($)\t" << "volume\t\t" << "profit($)" <<endl;
    for (auto i : customerAccount) {
        for(auto j :list){
            if(j->getName() ==i->getName()){
                cout << i->getName()+"\t"<<i->getPrice()<<"\t\t"<<j->getPrice()<<"\t\t"<< i->getQuantity()<<"\t\t" << getProfit(list,i->getName())<<"\t" <<endl;
                break;
            }
        }

    }
}

Customer::Customer( const string &name) :  name(name) {}



