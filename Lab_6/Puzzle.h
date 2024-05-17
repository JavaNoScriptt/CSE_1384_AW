#pragma once
/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: makes the class of puzzles that inherts inventory
*/
#include "Inventory.h"
using namespace std;
class Puzzle: public Inventory{
public:
	Puzzle(); // zero constructor
	Puzzle(string name, string itemDescription, string itemID, int stockNumber,
		string category,string ageRange, int peiceCount);
	//getters
	string getCategory();
	string getAgeRange();
	int getPieceCount();
	//setters
	void setCategory(string category);
	void setAgeRange(string ageRange);
	void setPieceCount( int peiceCount);
private:
	string category, ageRange;
	int peiceCount;
};

