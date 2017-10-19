//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Palindromes : 401 : Brayzen
//
//Data structure required : Strings, Array
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
	string norm = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
	string rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
	char reverse[91];
	for (int i = 0; i < norm.length(); i++) {
		reverse[norm[i]] = rev[i];
	}
	string message;
	while (cin >> message) {
		bool mirror = true;
		bool palin = true;
		int l = message.length();
		for (int i = 0; i < (l / 2) + 1; i++) {
			if (message[i] != message[l - 1 - i]) {
				palin = false;
			}
			if (message[l - 1 - i] != reverse[message[i]]) {
				mirror = false;
			}
			if (!palin && !mirror) {
				break;
			}
		}
		if (palin && mirror) {
			cout << message << " -- is a mirrored palindrome." << endl << endl;
		}
		else if (palin) {
			cout << message << " -- is a regular palindrome." << endl << endl;
		}
		else if (mirror) {
			cout << message << " -- is a mirrored string." << endl << endl;
		}
		else {
			cout << message << " -- is not a palindrome." << endl << endl;
		}
	}
	return 0;
}