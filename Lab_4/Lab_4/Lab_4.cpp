// Lab_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Name: Alex Woods NetID: ajw817
Date: 2/13/24 Due Date: 2/15/24
Description: currency calculator
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
// given to students
void sort(vector<float>& currencies);
void getCurrencies(vector<float>& currencies);
void breakdown(vector<float>& currencies);
int main()
{
	vector<float> currencies;
	// sets the two decimal places
	cout << fixed << setprecision(2);
	cout << "Welcome to the currency calculator." << endl << endl;
	// loop for the breakdowns the user wants to perform
	while (1)
	{
		// do they want to continue?
		string answer;
		cout << endl << "Would you like to enter a new price? (yes/no) ";
		cin >> answer;
		// answer validation
		while (answer != "yes" && answer != "no")
		{
			cout << endl << "Invalid answer. Try again." << endl;
			cout << "Would you like to enter a new price? (yes/no) ";
			cin >> answer;
		}
		if (answer == "no")
			break;
		// This is the only thing that I have added
		else if (answer == "yes") {
			getCurrencies(currencies);
			breakdown(currencies);
		}
		//end of what I have added
	}
	cout << endl << "Good-bye!" << endl;
	return 0;
}
// sorting algorithm given to students
// (bubble sort, for the curious)
void sort(vector<float>& currencies)
{
	for (int i = 0; i < currencies.size() - 1; i++)
	{
		for (int j = 0; j < currencies.size() - i - 1; j++)
		{
			if (currencies[j] < currencies[j + 1])
			{
				float temp = currencies[j];
				currencies[j] = currencies[j + 1];
				currencies[j + 1] = temp;
			}
		}
	}
}
void getCurrencies(vector<float>& currencies) {

	float currentCurrency;
	cout << "Enter in a -1 if you want to stop adding currencies!!!!!" << endl;
	cout << "Enter in a currency (0.01 - 100.0) "; 
	cin >> currentCurrency;
	while (currentCurrency != -1) {
		
		if ( currentCurrency <= 100) {
			if (currentCurrency > 0) {
				//cout << "Pushed" << endl;
				currencies.push_back(currentCurrency);
			}
		}
		
		cout << "Enter in a currency (0.01 - 100.0) ";
		cin >> currentCurrency;

		

	}
	cout << "Ended Currency gathering"<<endl;
	sort(currencies);
	for (int i = 0; i < currencies.size(); i++) {
		cout << currencies.at(i) << endl;
		
	}
	return;
}
void breakdown(vector<float>& currencies) {
	float currentCurrency;
	bool t_f;
	float one_minus;
	
	cout << "Enter in the currency that you would want to breakdown: ";
	cin >> currentCurrency;
	if (currentCurrency > 0) {
		t_f = true;
	}
	else { t_f = false; }
	while (currentCurrency < 0) {
		cout << "Error please enter in a better currency" << endl;
		cout << "Enter in the currency that you would want to breakdown: ";
		cin >> currentCurrency;
		if (currentCurrency > 0) {  t_f = true; }
		else { t_f = false; }
	}
	for (int i = 0; i < currencies.size(); i++) {
		/*if (currencies.at(i)> currentCurrency) {
			cout <<"0 "<< currencies.at(i) << endl;
		}*/
		if (currencies.at(i) < currentCurrency){ // wont print if the currency is greater than what your comparing against
			if (currencies.at(i) == 1.00) {// special case for 1
				int one_currency = floor(currentCurrency);
				if (one_currency >= 1) {
					cout << fixed << setprecision(0) << one_currency << " " << fixed << setprecision(2) << currencies.at(i) << " Bills" << endl;
					currentCurrency = currentCurrency - one_currency;
				}
			}
			else {
				/*
				
				Thsi revolves around two functions
				floor(currentCurrency / currencies.at(i)) which gets how much of a certian currency is needed

				(floor(currentCurrency / currencies.at(i)) * currencies.at(i)) which gets how much currency is used up
				
				*/
				if (floor(currentCurrency / currencies.at(i)) >= 1) {
					if (currencies.at(i) > 1) {
						cout << fixed << setprecision(0) << floor(currentCurrency / currencies.at(i)) << " " << fixed << setprecision(2) << currencies.at(i) << " Bills" << endl;
					}
					else {
						cout << fixed << setprecision(0) << floor(currentCurrency / currencies.at(i)) << " " << fixed << setprecision(2) << currencies.at(i)<< " Coins" << endl;
					}
					
					currentCurrency -= (floor(currentCurrency / currencies.at(i)) * currencies.at(i));
				}
			}
		}
		//cout << currencies.at(i) << endl;


	}



	return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
