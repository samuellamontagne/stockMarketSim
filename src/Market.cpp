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
