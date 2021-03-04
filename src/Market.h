/*
 * Market.h
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#ifndef MARKET_H_
#define MARKET_H_

#include <vector>
#include "Instruments.h"

using namespace std;

class Market {
private:
	vector<Instruments*> marketList;
public:
	Market();
	virtual ~Market();
	void addInstrument(Instruments* newInstr);
	//Update market function every time chunks should start from last day's price and wiggle it a little


};

#endif /* MARKET_H_ */
