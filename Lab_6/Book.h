#pragma once
#include "Inventory.h"
using namespace std;

/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: Makes the book class that inherits inventory class
*/


class Book :public Inventory{
public:
	Book(); // zero constructure
	Book(string name,string itemDescription, string itemID,
		int stockNumber, int pageNumber,string author,
		string genere, string publisher); // nonzero constructor
	//getters
	int getPageNumber();
	string getAuthor();
	string getGenre();
	string getPublisher();

	//setters
	void setPageNumber( int pageNumber);
	void setAuthor(string author);
	void setGenre(string genere);
	void setPublisher(string publisher);
	
private:
	int pageNumber;
	string author, genere, publisher;

};

