#include "cipher.h"

using namespace std;
/*
Name: Alex Woods NetID: ajw817
Date: 2/27/24 Due Date: 3/1/24
Description: This is the cpp file that defines what the function does in the cipher class.
*/

Cipher::Cipher() {
	text = "";
}
Cipher::Cipher(string text) {
	this->text = text; //shows that i know how to use pointers
}

//getting and setting functions
string Cipher::getText() {
	return text;
}
void Cipher::setText(string newText) {
	this->text = newText;
}

/*
Decoding and coding fucntions
*/
void Cipher::decode() {
	
	for (int i = 0; i < text.length(); i++) {
		//cout << text[i] << endl;

		if (text[i] >= 65 && text[i] <= 90) { // detects of the character is in the capital letter range

			if (text[i] - 5 > 90 || text[i] - 5 < 65) { // overflow of the letter range detector
				text[i] = text[i] + 21;
			}
			else {
				text[i] -= 5;
			}
		}
		else if (text[i] >= 97 && text[i] <= 122) { // same thing as the if statement but for lowercase

			if (text[i] - 5 > 122 || text[i] - 5 < 97) {// same thing as the if statement but for lowercase
				text[i] = text[i] + 21;
			}
			else {
				text[i] -= 5;
			}
		}



	}
	cout << text << endl;
	// milestone 1
	//text = "Decoding text"; 
}
void Cipher::encode() {
	
	for (int i = 0; i < text.length(); i++) {
		//cout << text[i] << endl;
		if (text[i]>=65 && text[i] <= 90) { // detects of the character is in the capital letter range

			if (text[i] + 5 > 90 || text[i] + 5 <65) { // detects if the range of the character is in the overflow range
				text[i] = text[i] - 21;
			}
			else {
				text[i] += 5;
			}
		} 
		else if (text[i] >= 97 && text[i] <= 122){ //char in the lowercase range
			if (text[i] + 5 > 122 || text[i] + 5 < 97) { // detects if the range of the character is in the overflow range
				text[i] = text[i] - 21;
			}
			else {
				text[i] += 5;
			}
		}
		
		
		
	}
	
	//milestone 1
	//text = "Encoding text";
}