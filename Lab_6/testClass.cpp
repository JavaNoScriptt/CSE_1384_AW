#include <iostream>

// student created classes
#include "book.h"
#include "puzzle.h"

using std::cout;
using std::endl;

int mainf()
{
    // testing empty constructors and setters
    Book book1;
    Puzzle puzz1;

    book1.setName("To Kill a Mockingbird");
    book1.setAuthor("Harper Lee");
    book1.setPublisher("Lipponcott");
    book1.setGenre("Southern Gothic");
    book1.setStockNumber(22);
    book1.setPageNumber(281);
    book1.setItemDescription("A book set in southern Alabama in the 1960s");
    book1.setItemID("101-289");

    puzz1.setName("Cavallini & Co - National Parks");
    puzz1.setPieceCount(1000);
    puzz1.setAgeRange("9+");
    puzz1.setCategory("Nature");
    puzz1.setItemDescription("A puzzle of the US National Parks");
    puzz1.setItemID("200-199");
    puzz1.setStockNumber(12);

    // testing constructor variants with parameters
    Book book2("The Road", "A post apocalyptic fiction novel", "100-100", 40,
        213, "Cormac McCarthy", "dystopian", "Penguin");
    Puzzle puzz2("Ravensburger Parisian Sunset", "A puzzle of the French Parisian sunset", "283-901", 5,
        "Landscapes", "12+", 500);


    // tests the getters (ie, output)
    cout << "Book " << book1.getItemID() << ": " << endl;
    cout << book1.getName() << " by " << book1.getAuthor() << endl;
    cout << "Description: " << book1.getItemDescription() << endl;
    cout << "Page number: " << book1.getPageNumber();
    cout << "\tGenre: " << book1.getGenre() << endl;
    cout << "Number in stock: " << book1.getStockNumber() << endl << endl;

    cout << "Book " << book2.getItemID() << ": " << endl;
    cout << book2.getName() << " by " << book2.getAuthor() << endl;
    cout << "Description: " << book2.getItemDescription() << endl;
    cout << "Page number: " << book2.getPageNumber();
    cout << "\tGenre: " << book2.getGenre() << endl;
    cout << "Number in stock: " << book2.getStockNumber() << endl << endl;


    cout << endl << "Puzzle " << puzz1.getItemID() << ":" << endl;
    cout << puzz1.getName() << " - " << puzz1.getPieceCount() << " pieces" << endl;
    cout << "Description: " << puzz1.getItemDescription() << endl;
    cout << "Ages: " << puzz1.getAgeRange();
    cout << "\tCategory: " << puzz1.getCategory() << endl;
    cout << "Number in stock: " << puzz1.getStockNumber() << endl << endl;

    cout << "Puzzle " << puzz2.getItemID() << ":" << endl;
    cout << puzz2.getName() << " - " << puzz2.getPieceCount() << " pieces" << endl;
    cout << "Description: " << puzz2.getItemDescription() << endl;
    cout << "Ages: " << puzz2.getAgeRange();
    cout << "\tCategory: " << puzz2.getCategory() << endl;
    cout << "Number in stock: " << puzz2.getStockNumber() << endl << endl;

    return 0;
}
