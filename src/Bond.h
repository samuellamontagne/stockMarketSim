/*
 * Bond.h
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#ifndef BOND_H_
#define BOND_H_
#include "Instruments.h"

class Bond : public Instruments {
public:
	Bond(string newName, double newPrice, int qte);
	void PrintInfo() const;
	void PrintForMarket() const;
};

#endif /* BOND_H_ */
