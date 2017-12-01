#include "simpleMC.h"
#include<iostream>
using namespace std;

int main(){
	double r, Expiry, Vol, Spot, Strike;
	char optionType;
	unsigned int NumberOfPaths;
	cout << "input spot price: " << endl;
	cin >> Spot;
	cout << "input riskless rate: " << endl;
	cin >> r;
	cout << "input volatility: " << endl;
	cin >> Vol;
	
	cout << "input the type of option(c for call, p for put):" << endl;
	cin >> optionType;
	cout << "input strike: " << endl;
	cin >> Strike;
	cout << "input expiry: " << endl;
	cin >> Expiry;
	
	cout << "input the number of calculating times of MC algorithm: " << endl;
	cin >> NumberOfPaths;
	
	double price;
	price = simpleMonteCarlo(Spot, r, Vol, Expiry, Strike, optionType, NumberOfPaths);
	cout << "the price of the option is " << price;
	return 0;
}
	
	
	