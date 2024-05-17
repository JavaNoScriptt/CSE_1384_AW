#include "Book.h"
/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: defines the functions of the book class
*/
using namespace std;

Book::Book() {
	this->name = ""; this->itemDescription = "";
	this->stockNumber = 0; this->pageNumber = 0;
	this->author = "";
	this->genere = ""; this->publisher = "";

}

Book::Book(string name, string itemDescription, string itemID,
	int stockNumber, int pageNumber, string author,
		string genere, string publisher) {
	this->name = name; this->itemDescription = itemDescription;
	this->stockNumber = stockNumber; this->pageNumber = pageNumber;
	this->author = author;
	this->genere = genere; this->publisher = publisher;
	this->itemID = itemID;
};
int Book::getPageNumber() {
	return pageNumber;
};

string Book::getAuthor() {
	return author;
};
string Book::getGenre() {
	return genere;
};
string Book::getPublisher() {
	return publisher;
};
void Book::setPageNumber(int pageNumber) {
	this->pageNumber = pageNumber;
};
void Book::setAuthor(string author) {
	this->author = author;
};
void Book::setGenre(string genere) {
	this->genere = genere;
};
void Book::setPublisher(string publisher) {
	this->publisher = publisher;
};