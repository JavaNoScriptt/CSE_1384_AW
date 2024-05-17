// lab-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// class include
#include "cipher.h"

// using statements
using std::string;
using std::getline;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    // welcome message
    cout << "Welcome to a Caesar cipher simulator." << endl;

    string option;

    // menu loop
    while (1)
    {
        // menu setup
        cout << endl << "0. Exit" << endl;
        cout << "1. Encode a Message" << endl;
        cout << "2. Decode a Message" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        // spacing
        cout << endl;

        // exit
        if (option == "0")
        {
            cout << "Good-bye!" << endl;
            break;
        }

        // encode
        else if (option == "1")
        {
            string word;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to encode: ";
            getline(cin, word);

            // creates a Cipher object and encodes
            Cipher text(word);
            text.encode();

            // displays to the user
            cout << endl << "Your encoded message is: " << text.getText() << endl;
        }

        // decode
        else if (option == "2")
        {
            // variable creation
            string word;
            Cipher text;
            cin.ignore(); // make sure getline works properly...

            cout << "Enter in a word/phase to decode: ";
            getline(cin, word);

            // sets the text using the setter
            // then decodes it
            text.setText(word);
            text.decode();

            // displays to the user
            cout << endl << "Your decoded message is: " << text.getText() << endl;
        }

        // wrong choice
        else
        {
            cout << "You entered an invalid option. Try again." << endl;
        }
    }

    return 0;
}
