#include <iostream>
#include <string>

using namespace std;

string buildEq(bool nested, string tab);
string verifyNumber(string item);

// funtions to make it easier to read
// gets and verifies numbers, tab is there for milestone #4
string getNumberOne(string tab); 
string getOperator(string tab);
string getNumberTwo(string tab);
bool recursionQ(string tab);
//bsically a copy of verifyNumber but for the operator
string verifyOperator(string item, string tab);

// end of student defined functions
int main()
{
    cout << "Welcome to the equation builder!" << endl << endl;

    cout << "Instructions: Each step can only have one operation between two numbers." << endl;
    cout << "So the equation (3 + 4) + 6 would have one 'nested' operation." << endl << endl;

    string equation = buildEq(false, "");

    cout << endl << "The equation you have built is... " << equation << endl;
    cout << endl << "Thanks for coming!" << endl;

    return 0;
}


string buildEq(bool nested, string tab)
{
    string equation;
    //Actual lab work
    string num1, num2, operatorStr;
    bool recursion = recursionQ(tab);
    if (recursion) { // if the recursion is true
        equation += "( ";
        num1 = buildEq(true, tab+"\t");
        operatorStr = getOperator(tab);
        num2 = getNumberTwo(tab);
        equation += num1 + " ) " + operatorStr + " " + num2;
    }
    else { // if no recursion
        num1 = getNumberOne(tab);
        operatorStr = getOperator(tab);
        num2 = getNumberTwo(tab);
        equation = num1 + " " + operatorStr + " " + num2;

    }
    

    //end of actual lab work
    return equation;
}


string verifyNumber(string item)
{
    // finds the index of the first character that doesn't match this set
    // if there's no character not in the set it returns -1
    int num = item.find_first_not_of("0123456789");

    // runs while a char other than what we want is present
    while(num > -1)
    {
        // error message
        cout << endl << "Error. An invalid character was present in the number." << endl;
        cout << "Please try again with characters 0-9 only." << endl;

        // and new input
        cout << endl << "Enter in a number: ";
        getline(cin, item);

        // retests...
        num = item.find_first_not_of("0123456789");
    }

    // returns validated number
    return item;
}

string getNumberOne(string tab) {
    string number; // initializing and asking for first number
    cout << tab << "Enter in the First number " ;
    cin >> number;
    cin.ignore();
    number  = verifyNumber(number); // checks if its correct
    cout << endl;
    return number;
}

string getOperator(string tab) {
    string operatorString;
    cout << tab << "What operation would you like to preform? " ;
    cin >> operatorString;
    cin.ignore();
    operatorString = verifyOperator(operatorString, tab); // verifies operation with tabs respected
    cout << endl;
    return operatorString;
};
string getNumberTwo(string tab) {
    string number;
    cout << tab << "Enter in the second number  " ;
    cin >> number;
    cin.ignore();
    number = verifyNumber(number);
    cout << endl;
    return number;
};


bool recursionQ(string tab) {

    bool ans;
    string ansQ;
    cout << endl << tab << "Is there recursion????? (y/n)";
    getline(cin, ansQ);
   // cin.ignore();
    while (ansQ !="y" && ansQ != "n") {
        cout << endl << tab << "*facepalms* you entered the wrong thing try again....   ";
        getline(cin, ansQ);
        
    }
    if (ansQ == "y") {
        ans = true;
    }
    else {
        ans = false;
    }
    cout << endl;
    return ans;
};

string verifyOperator(string item , string tab) {

    //keeps it to where its only one char and if they are a proper character
    while (item.length() != 1 || (item[0] != '*' && item[0] != '-' && item[0] != '+' && item[0] != '/')) {
        cout << endl << tab << "Error. Please enter a single valid operator (*, -, +, /): ";
        getline(cin, item);
    }
    return item;
    
};