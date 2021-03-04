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

void Bond::PrintInfo(){
	cout << "This is " << name << "'s stock." << endl;
	cout << "The price is currently at : " << price << "$" << endl;
	cout << "There is " << quantity << " stock available" << endl;
}
