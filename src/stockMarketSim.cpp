//============================================================================
// Name        : stockMarketSim.cpp
// Author      : Samuel Lamontagne
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "Instruments.h"
#include "Stock.h"
#include "Bond.h"

#define STARTING_CASH 100;   // init start money 100
#define MARKET_PERCENTAGE 0.1;
//Example NB_DAY_SIM = 10 and Increment = 1, is 10 days incrementing every days
//If you want to update 10x per day just change increment_sim 0.1
#define NB_DAYS_SIM 10;   //
#define INCREMENT_SIM 1;


using namespace std;


int main() {

    vector<Instruments>marketList;



	//Every chunk of time for all the chunks of time (NB_DAYS_SIM/INCREMENT_SIM)
	//We give the player options to buy and/or sell stocks
	//then we update the market prices and
	//Start a second day

	return 0;
}
