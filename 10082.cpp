//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : WERTYU : 10082 : Brayzen
//
//Data structure required : Array, String.
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string unshifted = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
	string shifted = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
	char newChar[256];
	for (int i = 0; i < unshifted.length(); i++) {
		newChar[unshifted[i]] = shifted[i];
	}
	string message;
	string newMessage;
	while (getline (cin, message)) {
		newMessage.clear();
		for (int i = 0; i < message.length(); i++) {
			if (message[i] == ' ') {
				newMessage.push_back(' ');
				continue;
			}
			char letter = newChar[message[i]];
			newMessage.push_back(letter);
		}
		cout << newMessage << endl;
	}

	return 0;
}