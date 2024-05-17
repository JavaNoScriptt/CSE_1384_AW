#include <iostream>
#include <string>

// class include
#include "cipher.h"

// using statements
using std::string;
using std::cout;
using std::endl;

int mainf()
{
    // uses empty constructor
    Cipher ex1;

    // uses constructor with parameters
    Cipher ex2("Testing words");


    // example 1 function calls
    cout << "Empty constructor variable:" << endl << endl;
    cout << "Text display: " << ex1.getText() << endl;

    ex1.setText("hello world");
    cout << "Text display after setText call: " << ex1.getText() << endl;

    ex1.encode();
    cout << "Text display after encode call: " << ex1.getText() << endl;

    ex1.decode();
    cout << "Text display after decode call: " << ex1.getText() << endl;



    // example 2 function calls
    cout << endl << endl << "Preset constructor variable:" << endl << endl;
    cout << "Text display: " << ex2.getText() << endl;

    ex2.setText("this is the second variable");
    cout << "Text display after setText call: " << ex2.getText() << endl;

    ex2.encode();
    cout << "Text display after encode call: " << ex2.getText() << endl;

    ex2.decode();
    cout << "Text display after decode call: " << ex2.getText() << endl;
    
    return 0;
}