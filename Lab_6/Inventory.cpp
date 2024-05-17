#include "Inventory.h"
/*
Name: Aelx Woods NetID: ajw817
Date: 3/5/24 Due Date: 3/8/24
Description: defines the functions in the inventory class
*/
using namespace std;

Inventory::Inventory() {
	this->itemDescription = "";
	this->itemID = "";
	this->name = "";
	this->stockNumber = 0;
	
}
string Inventory::getItemDescription() {
	return itemDescription;
}
string Inventory::getItemID() {
	return itemID;
}
string Inventory::getName() {
	return name;
}
int Inventory::getStockNumber(){
	return stockNumber;
}
void Inventory::setItemDescription(string itemDesc) {
	this->itemDescription = itemDesc;
}
void Inventory::setItemID(string itemID) {
	this->itemID = itemID;
}
void Inventory::setName(string name) {
	this->name = name;
}
void Inventory::setStockNumber(int stockNumber) {
	this->stockNumber = stockNumber;
}
