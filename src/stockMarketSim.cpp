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
#include "Market.h"
#include "Customer.h"
#include <typeinfo>
#include <iomanip>


#define MARKET_PERCENTAGE 0.1;
//Example NB_DAY_SIM = 10 and Increment = 1, is 10 days incrementing every days
//If you want to update 10x per day just change increment_sim 0.1
#define NB_DAYS_SIM 10;   //
#define INCREMENT_SIM 1;


using namespace std;


int main() {


	Stock* teslaStock = new Stock("TSLA", 10.00, 5000000);
	Bond* teslaBond = new Bond("TSLAB", 100.00, 10000);
	teslaBond->setExpireDate("2025-03-06");
	teslaBond->setFaceValue(100);
	teslaBond->setInterest(0.5);
	teslaBond->setYearDuration(4);
	teslaBond->setFrequenceOfPayInt(2);


	Stock* berkshireStock = new Stock("BRK", 25.00, 5000000);
	char userInput;


	Market stockMarket;
	string presentation;
	int nb_increments = 1/INCREMENT_SIM;
	int nb_days = NB_DAYS_SIM;
	int nb_rounds = (nb_increments * nb_days);

    stockMarket.addInstrument(teslaStock);
    stockMarket.addInstrument(teslaBond);
    stockMarket.addInstrument(berkshireStock);

	Customer customer("hello");

    stockMarket.addCustomerInMarket(&customer);

    customer.buy(teslaStock,10,100);
	cout << "current cash:"<<customer.getCash() << endl;
	cout << "current asset:"<<customer.calculateAsset(stockMarket.getMarketList()) << endl;
	cout << "current profit:"<<customer.getProfit(stockMarket.getMarketList()) << endl;
	cout << "current tesla volume:"<<teslaStock->getQuantity() << endl;

	teslaStock->updatePrice(20);

    cout << "current cash:"<<customer.getCash() << endl;
    cout << "current asset:"<<customer.calculateAsset(stockMarket.getMarketList()) << endl;
    cout << "current profit:"<<customer.getProfit(stockMarket.getMarketList()) << endl;


    customer.PrintInfo(stockMarket.getMarketList());

    customer.buy(teslaBond,100,10);


    stockMarket.payInterestToCustomer(teslaBond);

    customer.PrintInfo(stockMarket.getMarketList());




	cout << "Hi and welcome to our stock market simulation." << endl;

	cout << "This simulation will last " << nb_days << " days and will be updated " << nb_increments << " times per day." << endl << endl;
	//Every chunk of time for all the chunks of time (NB_DAYS_SIM/INCREMENT_SIM)

	for(int i = 0; i < nb_rounds; i++){

		cout << fixed << setprecision(2);

		//We give the customer options to buy and/or sell stocks

		cout << "This is the update " << i << " of " << nb_rounds << " updates for today" << endl;
		cout << "You are currently on day " <<  i/nb_days << " of " << nb_days << " days." << endl << endl;

		cout << "Here is what the market looks like today: " << endl << endl;

		stockMarket.printMarket();

		cout << endl;
		cout << "And here is your portfolio:" << endl << endl;

		//Print the person's portfolio


		cout << "Would you like to buy or sell today ? (y/n)" << endl;

		cin >> userInput;

		while(userInput != 'y' && userInput != 'n'){

			cout << "This input is invalid, enter y or n" << endl;

			cin >> userInput;
		}

		if(userInput == 'y'){

			cout << "Great ! Would you like to buy or sell ? (b/s)" << endl;



		} else if(userInput == 'n'){
			cout << "Great, then let's skip a day and see tomorrow's stock market !" << endl;
		}


		//then we update the market prices

		stockMarket.updateMarketPrices();


		//Start a second day

	}






	return 0;
}
