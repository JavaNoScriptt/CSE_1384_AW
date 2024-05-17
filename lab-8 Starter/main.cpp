#include <iostream>
#include <string>
#include <cmath>

#include "stack.h"

using namespace std;

string verifyValidOct(string oct);

int main()
{   
    string octuplete,y_N; //strign to Stack char and the loop enabler
    int decimal{}; //answer beign returned
    Stack stack_String; //Stack of the string
    while (y_N != "no") {
        octuplete,y_N = "","";
        
            cout << endl << "Enter in a octal number to convert: ";
            getline(cin, octuplete);
            //cout << octuplete << endl;
            octuplete = verifyValidOct(octuplete); // verifying octuplete
            //cout << octuplete << endl;
            //refactored code from the testStack file
            for (int i = 0; i < octuplete.size(); i++)
            {
                stack_String.add(octuplete[i]);
            }
            //actual math
            for (int i = 0; i < octuplete.size(); i++)
            {   
               //cout << decimal <<  endl;
               decimal = decimal + pow(8.0, i)* (int(stack_String.remove())-48);
            }
            cout << decimal << endl;

        //Asking user if they want to continue
        cout << "Would you want to enter another number? (yes/no)  " << endl;
        cin >> y_N;
        cin.ignore();
        while (y_N != "yes" || y_N != "no") {
            cout << "WRONG INPUT ENTER IN ONE OF THE CORRECT OPTIONS!!!!! " << endl;
            cin >> y_N;
            cin.ignore();
        }
    }
    cout << "goodbye!!!" << endl;

    return 0;
}

string verifyValidOct(string oct)
{
    // finds the index of the first character that doesn't match this set
    // if there's no character not in the set it returns -1
    int num = oct.find_first_not_of("01234567");

    // runs while a char other than what we want is present
    while(num > -1)
    {
        // error message
        cout << endl << "Error. An invalid character was present in the octal number." << endl;
        cout << "Please try again with characters 0-7 only." << endl;

        // and new input
        cout << endl << "Enter in a octal number to convert: ";
        getline(cin, oct);

        // retests...
        num = oct.find_first_not_of("01234567");
    }

    // returns validated number
    return oct;
}
