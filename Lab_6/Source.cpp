
//Proper include statements
#include <iostream>
#include <fstream>
#include <vector>
#include "book.h"
#include "puzzle.h"

using namespace std;

/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: This takes an input of a file and separates the contents into two different classes
*/



int main()
{
    //making all of the relevant variables
    vector<Book> books;
    vector<Puzzle> puzzles;
    ifstream infile;
    string name, txt_name, line;
    bool book{};
    int inc{};
    //initially asking for the name of the file

    /*
    Getting the file comes form how I accomplished it in the files lab with one exception
    exception: you hvae to put the file extenstion
    */

    cout << "enter the file name : ";
    cin >> name;
    txt_name = name;
    
    infile.open(txt_name);

    //this is a loop that i got from the class notes
    while (!infile.is_open()) {
        cout << "Error opening " << name<< endl;
        cout << "enter the file name : ";
        cin >> name;
        txt_name = name;
        infile.open(txt_name);

    }
    /* works for pushing back a class (testing purposes)
    books.push_back(Book());
    for (int i = 0; i < books.size(); i++) {
        cout << books[i].getPageNumber();

    }
    */

    while (getline(infile, line)) { // the infile.fail() is an operator that checks if an error has occured
        //cout << line << endl;
        if (line == "book") {
            book = true;
            
            inc = -1;
            books.push_back(Book());
        }
        else if (line == "puzzle") {
            book = false;
            inc = -1;
            puzzles.push_back(Puzzle());
        }
        if (book == true) {
            //the files are set in such a way so that each item comes one after another (name comes before description then item id and so on and so forth) 
            // switch statements are a logical way in my head to do this
            switch (inc) {
                
            case(0):
                books.back().setName(line);
                break;
            case(1):
                books.back().setItemDescription(line);
                break;
            case(2):
                books.back().setItemID(line);
                break;
            case(3):
                books.back().setStockNumber(stoi(line)); //learned that stoi exist (string to int)
                break;
            case(4):
                books.back().setPageNumber(stoi(line));
                break;
            case(5):
                books.back().setAuthor(line);
                break;
            case(6):
                books.back().setGenre(line);
                break;
            case(7):
                books.back().setPublisher(line);
                break;
            };
            inc++; // incrementing to go to the next case for the switch statement

        }

        // same thing as the last if statement but for puzzles instead of
        else if (book == false) {
            /*
            string name, string itemDescription, string itemID, int stockNumber,
    string category, string ageRange, int peiceCount
            */
            switch (inc) {
            case(0):
                puzzles.back().setName(line);
                break;
            case(1):
                puzzles.back().setItemDescription(line);
                break;
            case(2):
                puzzles.back().setItemID(line);
                break;
            case(3):
                puzzles.back().setStockNumber(stoi(line));
                break;
            case(4):
                puzzles.back().setCategory(line); //learned that stoi exist (string to int)
                break;
            case(5):
                puzzles.back().setAgeRange(line);
                break;
            case(6):
                puzzles.back().setPieceCount(stoi(line));
                break;
            };
            inc++; // incrementing to go to the next case for the switch statement





        }
    }
    /* works for pushing back a class*/
    cout << "Books:" << endl << endl;
    for (int i = 0; i < books.size(); i++) {
        // proper form of each book
        cout << "Book " << books[i].getItemID() << ":" << endl;
        cout << books[i].getName() << " by " << books[i].getAuthor() << endl;
        cout << "Description: " << books[i].getItemDescription() << endl;
        cout << "Page Number: " << books[i].getPageNumber() << "\t\tGenre: " << books[i].getGenre() << endl;
        cout << "Number in stock: " << books[i].getStockNumber() << endl << endl << endl;
        /*
         //this was for testing if all the outputs are correct
        cout << books[i].getName() << endl;
        cout << books[i].getItemDescription() << endl;
        cout << books[i].getItemID() << endl;
        cout << books[i].getStockNumber() << endl;
        cout << books[i].getPageNumber() << endl;
        cout << books[i].getAuthor() << endl;
        cout << books[i].getGenre() << endl;
        cout << books[i].getPublisher() << endl;
        */
    };
    cout << endl << "Puzzles:" << endl << endl;
        for (int i = 0; i < puzzles.size(); i++) {

            //proper form of each puzzle
            cout << "Puzzle " << puzzles[i].getItemID() <<":" << endl;
            cout << puzzles[i].getName() << " - " << puzzles[i].getPieceCount() << " Peices" << endl;
            cout << "Description: " << puzzles[i].getItemDescription() << endl;
            cout << "Ages: " << puzzles[i].getAgeRange() << "\t\tCategory: " << puzzles[i].getCategory() << endl;
            cout << "Number in stock: " << puzzles[i].getStockNumber() << endl << endl << endl;
            /*
            //testing purposes
            cout << puzzles[i].getName() << endl;
            cout << puzzles[i].getItemDescription() << endl;
            cout << puzzles[i].getItemID() << endl;
            cout << puzzles[i].getStockNumber() << endl;
            cout << puzzles[i].getCategory() << endl;
            cout << puzzles[i].getAgeRange() << endl;
            cout << puzzles[i].getPieceCount() << endl;
            */
        };
        return 0;
    };

        


