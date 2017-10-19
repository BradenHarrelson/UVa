//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Splitting Numbers : 11933 : Brayzen
//
//Data structure required : Bitsets
//
//Tricks of the trade : 
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <bitset>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num;
	while (cin >> num && num != 0) {
		bitset<32> bitNum(num);
		bitset<32> subNum1;
		bitset<32> subNum2;
		bool check = true;
		for (int i = 0; i < 32; i++) {
			//if digit is 1
			if (bitNum[i]) {
				//copy to sub sets
				if (check) {
					subNum1[i] = bitNum[i];
				}
				else {
					subNum2[i] = bitNum[i];
				}
				//flip bool in order to alternate where next 1 goes
				check = !check;
			}
		}
		//output
		cout << subNum1.to_ulong() << " " << subNum2.to_ulong() << "\n";
	}
	return 0;
}