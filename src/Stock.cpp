/*
 * Stock.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Stock.h"

using namespace std;

Stock::Stock(string newName, double newPrice, int qte):Instruments(newName, newPrice, qte) {}

void Stock::PrintInfo() const{
	cout << "This is " << name << "'s stock." << endl;
	cout << "The price is currently at : " << price << "$" << endl;
	cout << "There is " << quantity << " stock available" << endl;
}

