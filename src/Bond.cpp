/*
 * Bond.cpp
 *
 *  Created on: Mar. 4, 2021
 *      Author: samuel
 */

#include "Bond.h"

#include <utility>

Bond::Bond(string newName, double newPrice, int qte): Instruments(newName, newPrice, qte) {
	// TODO Auto-generated constructor stub

}

void Bond::PrintInfo() const{
	cout << "This is " << name << "'s bond." << endl;
	cout << "The price is currently at : " << price << "$" << endl;
	cout << "There is " << quantity << " stock available" << endl;
}

double Bond::getInterest() const {
    return interest;
}

void Bond::setInterest(double interest) {
    Bond::interest = interest;
}

const string &Bond::getExpireDate() const {
    return expireDate;
}

void Bond::setExpireDate(const string &expireDate) {
    Bond::expireDate = expireDate;
}

const int &Bond::getYearDuration() const {
    return yearDuration;
}

void Bond::setYearDuration(const int &yearDuration) {
    Bond::yearDuration = yearDuration;
}


void Bond::PrintForMarket() const{
	cout << "Name: " << name << "; Price per bond: $" << price << "; Quantity available: " << quantity << endl;
}

double Bond::getFaceValue() const {
    return faceValue;
}

void Bond::setFaceValue(double faceValue) {
    Bond::faceValue = faceValue;
}

int Bond::getFrequenceOfPayInt() const {
    return frequenceOfPayInt;
}

void Bond::setFrequenceOfPayInt(int frequenceOfPayInt) {
    Bond::frequenceOfPayInt = frequenceOfPayInt;
}


