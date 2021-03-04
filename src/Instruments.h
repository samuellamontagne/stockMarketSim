/*
 * Instruments.h
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#ifndef INSTRUMENTS_H_
#define INSTRUMENTS_H_
#include <iostream>

using namespace std;

class Instruments {
private:
	double price;
	int quantity;
	string name;
public:
	Instruments(string newName, double newPrice, int qte);
	virtual ~Instruments();

	virtual void PrintInfo() const = 0;


};

#endif /* INSTRUMENTS_H_ */
