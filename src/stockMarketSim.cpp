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
	Bond* teslaBond = new Bond("TSLAB", 10.00, 5000000);

	Stock* berkshireStock = new Stock("BRK", 25.00, 5000000);
	char userInput;

	Instruments* tempStock;


	Market stockMarket;
	string presentation;
	string instrumentsName;
	int nbToUse;

	string customerName;
	int nb_increments = 1/INCREMENT_SIM;
	int nb_days = NB_DAYS_SIM;
	int nb_rounds = (nb_increments * nb_days);

    stockMarket.addInstrument(teslaStock);
    stockMarket.addInstrument(teslaBond);
    stockMarket.addInstrument(berkshireStock);


/*	Customer customerTest("hello");
	customerTest.buy(teslaStock,10,100);
	cout << "current cash:"<<customerTest.getCash() << endl;
	cout << "current asset:"<<customerTest.calculateAsset(stockMarket.getMarketList()) << endl;
	cout << "current profit:"<<customerTest.getProfit(stockMarket.getMarketList()) << endl;
	cout << "current tesla volume:"<<teslaStock->getQuantity() << endl;

	teslaStock->updatePrice(20);

    cout << "current cash:"<<customerTest.getCash() << endl;
    cout << "current asset:"<<customerTest.calculateAsset(stockMarket.getMarketList()) << endl;
    cout << "current profit:"<<customerTest.getProfit(stockMarket.getMarketList()) << endl;


    customerTest.PrintInfo(stockMarket.getMarketList());*/


	cout << "Hi and welcome to our stock market simulation." << endl;

	cout << "Tell me your name !" << endl;

	cin >> customerName;

	cout << "Hello, " << customerName << " and good luck !";

	Customer mainCustomer(customerName);



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
		mainCustomer.PrintInfo(stockMarket.getMarketList());

		cout << endl;
		cout << "Would you like to buy or sell today ? (y/n)" << endl;

		cin >> userInput;

		while(userInput != 'y' && userInput != 'n'){

			cout << "This input is invalid, enter 'y' to buy/sell or 'n' to skip a day" << endl;

			cin >> userInput;
		}

		if(userInput == 'y'){

			cout << "Great ! Would you like to buy or sell ? (b/s)" << endl;
			while(userInput != 'b' && userInput != 's'){

				cout << "This input is invalid, enter 'b' to buy or 's' to sell" << endl;

				cin >> userInput;
			}

			do{

				if(userInput == 'b'){
					//what instrument to buy

					cout << "What instrument would you like to buy ?(Enter the name)" << endl;
					cin >> instrumentsName;

					//how much to buy

					cout << "How much would you like to buy ?" << endl;

					cin >> nbToUse;

					tempStock = stockMarket.returnInstByName(instrumentsName);

					mainCustomer.buy(tempStock, tempStock->getPrice(), nbToUse);


				} else if(userInput == 's'){
					//what instrument to sell
					cout << "What instrument would you like to sell ?(Enter the name)" << endl;
					cin >> instrumentsName;

					//how much to sell

					cout << "How much would you like to sell ?" << endl;

					cin >> nbToUse;

					tempStock = stockMarket.returnInstByName(instrumentsName);

					mainCustomer.sell(tempStock, tempStock->getPrice(), nbToUse);
				}

				//Want to buy or sell again ?
				cout << "Do you want to buy or sell again ? (y/n)" << endl;
				while(userInput != 'y' && userInput != 'n'){

					cout << "This input is invalid, enter 'y' to buy/sell or 'n' to skip a day" << endl;

					cin >> userInput;
				}

				if(userInput == 'y'){
					cout << "Great ! Would you like to buy or sell ? (b/s)" << endl;
					while(userInput != 'b' && userInput != 's'){

						cout << "This input is invalid, enter 'b' to buy or 's' to sell" << endl;

						cin >> userInput;
					}
				}


			}while(userInput == 'b' || userInput == 's');


		} else if(userInput == 'n'){
			cout << "Great, then let's skip a day and see tomorrow's stock market !" << endl;
		}


		//then we update the market prices

		cout << "Ok, the day is over. Let's see the prices tomorrow !" << endl;

		stockMarket.updateMarketPrices();


		//Start a second day

	}






	return 0;
}
