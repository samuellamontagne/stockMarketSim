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
#include "Customer.h"

using namespace std;



class Market {
private:
	vector<Instruments*> marketList;
    vector<Customer*>customerList;
public:
	Market();

    const vector<Customer *> &getCustomerList() const;

    void setCustomerList(const vector<Customer *> &customerList);

    const vector<Instruments *> &getMarketList() const;

    void setMarketList(const vector<Instruments *> &marketList);

    virtual ~Market();
	void addInstrument(Instruments* newInstr);
	//Update market function every time chunks should start from last day's price and wiggle it a little
	void updateMarketPrices();

	void printMarket();

    void payInterestToCustomer( Bond* bond);

    bool addCustomerInMarket(Customer* customer);
};

#endif /* MARKET_H_ */
