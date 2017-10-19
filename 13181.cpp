//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Sleeping in Hostels : 13181 : Brayzen
//
//Data structure required : String
//
//Tricks of the trade :
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string line;
	while (cin >> line) {
		int ct = 0, maxDist = 0;
		//bool to handle if no sleeping on first bed
		bool hitX = false;
		for (int i = 0; i < line.length(); i++) {
			//if ".": increment counter, check if last bed, check maxD
			if (line[i] == '.') {
				ct++;
				if (i == line.length() - 1) {
					ct = 2 * ct;
				}
				if (ct > maxDist) {
					maxDist = ct;
				}
			}
			//if "X": check if first X, reset counter, change X bool
			else {
				if (!hitX) {
					maxDist = 2 * maxDist;
				}
				ct = 0;
				hitX = true;
			}
		}
		//check if even sized distance, have to pick one of the middle
		if (maxDist % 2 == 0) {
			cout << maxDist / 2 - 1 << "\n";
		}
		else {
			cout << maxDist / 2 << "\n";
		}
	}
	return 0;
}