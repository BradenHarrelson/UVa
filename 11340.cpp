//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Newspaper : 11340 : Brayzen
//
//Data structure required : vector, string
//
//Tricks of the trade : ASCII manipulation
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); //speed
	int tests, cases, val, lines;
	char letter;
	string textLine;
	double sum;
	cin >> tests;
	for (int i = 0; i < tests; i++) {
		sum = 0.0;
		vector<int> chars(256, 0);
		cin >> cases;
		//fill char array indexed by ASCII chars
		for (int j = 0; j < cases; j++) {
			cin >> letter >> val;
			chars[letter] = val;
		}
		cin >> lines;
		cin.ignore(); //switching from cin to getline
		double sum = 0.0;
		//now loop through each line of text to check vals
		for (int k = 0; k < lines; k++) {
			getline(cin, textLine);
			for (int p = 0; p < textLine.length(); p++) {
				sum += chars[textLine[p]];
			}
		}
		cout << fixed << setprecision(2) << sum / 100 << "$\n";
	}
	return 0;
}