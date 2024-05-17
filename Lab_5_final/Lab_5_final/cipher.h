#pragma once
#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>
using namespace std;

class Cipher {

public:
	Cipher();
	Cipher(string text);
	void encode();
	void decode();
	void setText(string text);
	string getText();
private:
	string text = "";
	int shift = -5;
};
#endif 