/*
Name: Alex Woods            NetID: ajw817
Date: 1/26/24               Due Date: 2/5/24 @23:59

Description: This is a simple program that determines the best car to use out of 
a selected range of cars depending on the price of trip that is taking place. 
Using the text format of the canvas assignment.

*/
#include <iostream>
#include <string>
#include <math.h> //This is the std C library. cmath is C++
using namespace std;
int main()
{
    // milestone #1 (Part 1): initalizing the variables and getting the basic info
    
    // intializes all of the variables
    int tot_miles, num_cars, MPG, tank_cap, num_tanks;

    // the winning trip being set to zero is used later in the program (Milestone 4)
    double gas_price, trip_price, winning_trip_price = 0.0; 

    string car_name, winning_car = " ";

    std::cout << "Welcome to the mileage Calculator!!!\n\nHow far in miles is your journey? ";
    cin >> tot_miles; // gets how many miles are in the trip

    std::cout << "What is the average price of gas for your Journey? " ;
    cin >> gas_price; // gets the price of gas (I want the irl gas price to be low but thats just me)

    std::cout << "How many cars are you comparing? ";
    cin >> num_cars; // getting the number of cars being compared which is the basis of the later milestones


    /* // MileStone #1 (Part2): looping over how many cars the user puts
    for (int i = 1; i < num_cars +1; i++) {
    std:cout << "Car " << i << endl;
    }
    */
    //Milestone #2: Entering information into the loop
    for (int i = 1; i < num_cars + 1; i++) {

        //Getting the car name
        std::cout << "Enter the name of car " << i << ": ";
        cin.ignore();
        getline(cin, car_name);//using getline specifically because car names is normally spaced out

        std::cout << "Enter the MPG (Miles Per Gallon): ";
        cin >> MPG; //gets the car MPG

        std::cout << "Enter the tank capacity (In Gallons): ";
        cin >> tank_cap;// gets how many gallons are in the cars tank. 

        //outputing the information on the given car. 
        std::cout << "Your " << car_name << " has " << MPG << " Miles Per Gallon " << " and a " << tank_cap << " tank capacity."<<endl;

        ///Milestone #3: doing the math on the cars stats

        // first equatuion is rounded to the whole number because of have only an integer amoutn of tanks. 
        // I got both of these equations by trying the parameters that the test program uses in canvas  until I got the correct answer
        num_tanks = ceil(tot_miles / MPG / tank_cap);
        trip_price = num_tanks * tank_cap * gas_price;

        std::cout << endl << "Your " << car_name << " will need " << num_tanks << "." << endl;
        std::cout << "This will cost $" << trip_price << endl;
        /* Milestone #4: The best car is determined then outputed
        As I saw in the canvas assignment the winning trip is determined on which car has the lowest trip. So The program keeps a running
        tally on which car is the best car by comparing the current car to the current best price.
        The initialized 0 on the winning_trip_price is so that the first car always becomes the winning car be default.
        */
        
        if (winning_trip_price == 0 || trip_price < winning_trip_price) {
            winning_car = car_name;
            winning_trip_price = trip_price;
        }
        
    }
    // outputs the winning car to the console. 
    std::cout << "Your best option is the " << winning_car << " at $" <<  winning_trip_price;
    return 0;
}

