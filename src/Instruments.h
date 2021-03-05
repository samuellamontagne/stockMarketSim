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

public:
	Instruments(string newName, double newPrice, int qte);
	virtual ~Instruments(){};

    Instruments(const Instruments&  instrument);
	virtual void PrintInfo() const = 0;

    const string &getName() const;

    void setName(const string &name);



    int getQuantity() const;

    void setQuantity(int quantity);

    void updatePrice(double newPrice);
	double getPrice();

protected:
	string name;
	double price;
	int quantity;
};

#endif /* INSTRUMENTS_H_ */
