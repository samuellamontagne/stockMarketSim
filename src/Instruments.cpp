/*
 * Instruments.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Instruments.h"

Instruments::Instruments(string newName, double newPrice, int qte):name(newName), price(newPrice), quantity(qte) {}

void Instruments::updatePrice(double newPrice){
	price = newPrice;
}

double Instruments::getPrice(){
	return price;
}
