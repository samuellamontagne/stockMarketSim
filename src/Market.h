/*
 * Market.h
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#ifndef MARKET_H_
#define MARKET_H_

#include <vector>
#include <time.h>
#include "Instruments.h"

using namespace std;

class Market {
private:
	vector<Instruments*> marketList;
public:
	Market();

    const vector<Instruments *> &getMarketList() const;

    void setMarketList(const vector<Instruments *> &marketList);

    virtual ~Market();
	void addInstrument(Instruments* newInstr);
	//Update market function every time chunks should start from last day's price and wiggle it a little
	void updateMarketPrices();
};

#endif /* MARKET_H_ */
