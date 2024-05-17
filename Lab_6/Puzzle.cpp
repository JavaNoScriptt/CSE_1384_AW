#include "Puzzle.h"
Puzzle::Puzzle() { //zero constructor
	this->name = ""; this->itemDescription = ""; this->itemID = "";
	this->stockNumber = 0;
	this->category = ""; this->ageRange = ""; this->peiceCount = 0;
	this->category = ""; this->ageRange = ""; this->peiceCount = 0;
}
Puzzle::Puzzle(string name, string itemDescription, string itemID, int stockNumber,
	string category, string ageRange, int peiceCount) {
	this->name = name; this->itemDescription = itemDescription; this->itemID = itemID; 
	this->stockNumber = stockNumber;
	this->category = category; this->ageRange = ageRange; this->peiceCount = peiceCount;
}
//getters
string Puzzle::getCategory(){
	return category;
}
string Puzzle::getAgeRange(){
	return ageRange;
}
int Puzzle::getPieceCount() {
	return peiceCount;
}
//setters
void Puzzle::setCategory(string category){
	this->category = category;
}
void Puzzle::setAgeRange(string ageRange) {
	this->ageRange = ageRange;
}
void Puzzle::setPieceCount(int peiceCount) {
	this->peiceCount = peiceCount;
}