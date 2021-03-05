/*
 * Instruments.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Instruments.h"

Instruments::Instruments(string newName, double newPrice, int qte):name(newName), price(newPrice), quantity(qte) {}




int Instruments::getQuantity() const {
    return quantity;
}

void Instruments::setQuantity(int quantity) {
    Instruments::quantity = quantity;
}

const string &Instruments::getName() const {
    return name;
}

void Instruments::setName(const string &name) {
    Instruments::name = name;
}

void Instruments::updatePrice(double newPrice){
	price = newPrice;
}

double Instruments::getPrice(){
	return price;
}




