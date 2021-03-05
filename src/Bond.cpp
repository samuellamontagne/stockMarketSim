/*
 * Bond.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Bond.h"

Bond::Bond(string newName, double newPrice, int qte): Instruments(newName, newPrice, qte) {
	// TODO Auto-generated constructor stub

}

void Bond::PrintInfo() const{
	cout << "This is " << name << "'s bond." << endl;
	cout << "The price is currently at : " << price << "$" << endl;
	cout << "There is " << quantity << " stock available" << endl;
}

void Bond::PrintForMarket() const{
	cout << "Name: " << name << "; Price per bond: $" << price << "; Quantity available: " << quantity << endl;
}
