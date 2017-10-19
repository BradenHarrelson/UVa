//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Basically Speaking : 389 : Brayzen
//
//Data structure required : Vectors, strings
//
//Tricks of the trade : ascii indexing, Horners method
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//fill ascii table with values
	vector<int> numTable(127);
	for (int i = 0; i < 10; i++) {
		numTable[48 + i] = i;
	}
	for (int i = 0; i < 6; i++) {
		numTable[65 + i] = 10 + i;
	}
	vector<char> charTable(16);
	string input;
	int from, to, temp;
	long long bTen;
	while (cin >> input >> from >> to) {
		if (input.length() > 1) {
			//use Horners Method here
			bTen = numTable[input[0]];
			for (int i = 1; i < input.length(); i++) {
				bTen = bTen * from + numTable[input[i]];
			}
		}
		//if only one digit
		else {
			bTen = numTable[input[0]];
		}
		//only convert bases if not 10
		if (to != 10) {
			string newBase = "";
			int num = bTen;
			if (num > 0) {
				while (num != 0) {
					temp = num % to;
					num = num / to;
					//turn int back to char so we can put into string
					if (temp > 9) {
						temp = temp + 55;
					}
					else {
						temp = temp + 48;
					}
					char cTemp = temp;
					newBase = cTemp + newBase;
				}
			}
			//if bTen is 0
			else {
				newBase = "0";
			}
			//output after converting from base 10
			if (newBase.length() < 8) {
				cout << right << setw(7) << newBase << "\n";
			}
			else {
				cout << "  ERROR" << "\n";
			}
		}
		//output if base 10 was final base
		else {
			if (bTen < 10000000) {
				cout << right << setw(7) << bTen << "\n";
			}
			else {
				cout << "  ERROR" << "\n";
			}
		}
	}
	return 0;
}