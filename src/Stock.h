/*
 * Stock.h
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#ifndef STOCK_H_
#define STOCK_H_
#include "Instruments.h"

class Stock : public Instruments {
public:
	Stock(string newName, double newPrice, int qte);
	void PrintInfo() const;
};

#endif /* STOCK_H_ */
