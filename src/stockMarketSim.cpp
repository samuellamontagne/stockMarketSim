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
	teslaBond->setInterest(2.5);
	teslaBond->setYearDuration(4);
	teslaBond->setFrequenceOfPayInt(2);
	vector<Bond*> bondsToPay;


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


	Customer customer("hello");
    stockMarket.addCustomerInMarket(&customer);
    customer.buy(teslaStock,10,100);



	teslaStock->updatePrice(20);


    customer.PrintInfo(stockMarket.getMarketList());
    customer.buy(teslaBond,100,50);
    customer.PrintInfo(stockMarket.getMarketList());
    stockMarket.payInterestToCustomer(teslaBond);
    customer.PrintInfo(stockMarket.getMarketList());

    customer.buy(teslaStock,20,50);

    customer.PrintInfo(stockMarket.getMarketList());

//    for(Instruments* b : stockMarket.getMarketList()){
//        if(typeid(*b) == typeid(Bond)){
//            Bond* currBond = (dynamic_cast<Bond*>(b));
//            cout << "----------"<<currBond->getFrequenceOfPayInt()<<endl;
//
//        }
//    }






	cout << "Hi and welcome to our stock market simulation." << endl;

	cout << "Tell me your name !" << endl;

	cin >> customerName;

	cout << "Hello, " << customerName << " and good luck !";

	Customer mainCustomer(customerName);

	stockMarket.addCustomerInMarket(&mainCustomer);

	cout << "This simulation will last " << nb_days << " days and will be updated " << nb_increments << " times per day." << endl << endl;
	//Every chunk of time for all the chunks of time (NB_DAYS_SIM/INCREMENT_SIM)

	for(int i = 0; i < nb_rounds; i++){

		cout << fixed << setprecision(2);

		//We give the customer options to buy and/or sell stocks

		cout << "This is the update " << i << " of " << nb_rounds << " updates for today" << endl;
		cout << "There are " <<  nb_days-i << " left." << endl << endl;

		cout << "Here is what the market looks like today: " << endl << endl;

		stockMarket.printMarket();

		//Not able to make an Instrument* to a Bond* and access it's methods
		bondsToPay = mainCustomer.bondsToBePaid(i+1);

		for(size_t j = 0; j < bondsToPay.size(); j++){
			stockMarket.payInterestToCustomer(bondsToPay.at(j));
			cout << "Interest for bond: " << bondsToPay.at(j)->getName() << " has been paid !" << endl;
			//Cash of the customer is not being updated (not being put in cash) ......
			//PROBLEM FOUND : problem is when in Customer::buy, the object is not being copied properly and the attributes are lost

		}

		cout << endl;
		cout << "And here is your portfolio:" << endl << endl;

		//Print the person's portfolio
//		mainCustomer.PrintInfo(stockMarket.getMarketList());
        mainCustomer.PrintInfo(stockMarket.getMarketList());

		cout << endl;

		do{

			cout << endl;
			cout << "Menu: " << endl;
			cout << "s - Sell Instruments" << endl;
			cout << "b - Buy Instruments" << endl;
			cout << "p - Print the Market" << endl;
			cout << "c - Print your Portfolio" << endl;
			cout << "q - Go to next update" << endl;
			cout << "Choose an option: ";

			cin >> userInput;

			while(userInput != 's' && userInput != 'b' && userInput != 'p' && userInput != 'c' && userInput != 'q'){
				cout << endl;
				cout << "Choose an option: ";

				cin >> userInput;
			}
			cout << endl << endl;

			switch(userInput){
			case('b'):
					//what instrument to buy

					cout << "What instrument would you like to buy ?(Enter the name)" << endl;
					cin >> instrumentsName;

					while(stockMarket.checkForStockByName(instrumentsName) == -1){
						cout << "This stock is not in the market ! Enter a new name." << endl;
						cin >> instrumentsName;
					}

					//how much to buy

					cout << "How much would you like to buy ?" << endl;

					cin >> nbToUse;

					tempStock = stockMarket.returnInstByName(instrumentsName);

					mainCustomer.buy(tempStock, tempStock->getPrice(), nbToUse);
					break;
			case('s'):
					//what instrument to sell
					cout << "What instrument would you like to sell ?(Enter the name)" << endl;
					cin >> instrumentsName;

					//how much to sell

					cout << "How much would you like to sell ?" << endl;

					cin >> nbToUse;

					tempStock = stockMarket.returnInstByName(instrumentsName);

					mainCustomer.sell(tempStock, tempStock->getPrice(), nbToUse);
					break;
			case('p'):
					cout << "Here is what the market looks like today: " << endl << endl;

					stockMarket.printMarket();
					break;
			case('c'):
					cout << "Here is your portfolio:" << endl << endl;

					//Print the person's portfolio
					mainCustomer.PrintInfo(stockMarket.getMarketList());
					break;
			case('q'):
					cout << "Great, then let's skip a day and see tomorrow's stock market !" << endl;
			}

		}while(userInput != 'q');

		//then we update the market prices

		cout << "Ok, the day is over. Let's see the prices tomorrow !" << endl;

		stockMarket.updateMarketPrices();


		//Start a second day


	}






	return 0;
}
