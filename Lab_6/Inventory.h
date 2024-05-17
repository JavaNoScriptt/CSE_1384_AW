#pragma once
using namespace std;
#include <string>
/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: makes the class of inventory which the book and puzzle classes inherits
*/
class Inventory
{

public:
	Inventory();
	string getName();
	string getItemDescription();
	string getItemID();
	int getStockNumber();
	void setName(string name);
	void setItemDescription(string itemDescription);
	void setItemID(string itemID);
	void setStockNumber(int stockNumber);
protected:
	string name, itemDescription, itemID;
	int stockNumber;
};

