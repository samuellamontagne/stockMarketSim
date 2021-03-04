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
	Stock();
	virtual ~Stock();
};

#endif /* STOCK_H_ */
