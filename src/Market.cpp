/*
 * Market.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Market.h"

Market::Market() {
}

Market::~Market() {
	for(size_t i=0; i < marketList.size(); i++){
		delete marketList.at(i);
	}
}

void Market::addInstrument(Instruments* newInstr){
	marketList.push_back(newInstr);
}

void Market::updateMarketPrices(){
	double newPrice = 0;
	double oldPrice = 0;
	//Random factor between 0.5 and 1.5
	double randomFactor = 0;
	srand((unsigned)time(NULL));

	for(size_t i = 0; i < marketList.size(); i++){
		oldPrice = marketList.at(i)->getPrice();
		randomFactor = (double) rand()/RAND_MAX + 0.5;
		newPrice = oldPrice * randomFactor;
		marketList.at(i)->updatePrice(newPrice);
	}
}

const vector<Instruments *> &Market::getMarketList() const {
	return marketList;
}

void Market::setMarketList(const vector<Instruments *> &list) {
	Market::marketList = list;
}

void Market::printMarket(){
	for(size_t i = 0; i < marketList.size(); i++){
		marketList.at(i)->PrintForMarket();
	}
}

bool Market::addCustomerInMarket(Customer* custormer) {
    for (Customer* c: customerList) {
        if(c->getName()==custormer->getName()){
            cout << "customer exit, Please get a new name;"<<endl;
            return false;
        }
    }
    customerList.push_back(custormer);
    return true;
}

void Market::payInterestToCustomer( Bond* bond) {

    for (Customer* c : customerList) {
        for(Instruments* i:  c->getCustomerAccount()){
           if(i->getName()==bond->getName()){
               c->setCash(c->getCash()+i->getQuantity()*bond->getInterest()/100);
           }
        }
    }

}

const vector<Customer *> &Market::getCustomerList() const {
    return customerList;
}

void Market::setCustomerList(const vector<Customer *> &customerList) {
    Market::customerList = customerList;
}


Instruments* Market::returnInstByName(string name){
	Instruments* toSend;
	for(size_t i = 0; i < marketList.size(); i++){
		if(marketList.at(i)->getName() == name){
			toSend = marketList.at(i);
			break;
		}
	}
	return toSend;
}
