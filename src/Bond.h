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

    double getFaceValue() const;

    void setFaceValue(double faceValue);
    double getInterest() const;

    void setInterest(double interest);

    const string &getExpireDate() const;

    void setExpireDate(const string &expireDate);

    const int &getYearDuration() const;

    void setYearDuration(const int &yearDuration);

    Bond(string newName, double newPrice, int qte);
    void PrintInfo() const;


    int getFrequenceOfPayInt() const;

    void setFrequenceOfPayInt(int frequenceOfPayInt);

private:
    double faceValue;
    string expireDate;
    int yearDuration;
    double interest;
    int frequenceOfPayInt;

	void PrintForMarket() const;
};

#endif /* BOND_H_ */
