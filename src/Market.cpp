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
	for(size_t i; i < marketList.size(); i++){
		delete marketList.at(i);
	}
}

void Market::addInstrument(Instruments* newInstr){
	marketList.push_back(newInstr);
}

