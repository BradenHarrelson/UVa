//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Rotations : 13193 : Brayzen
//
//Data structure required : Bitset
//
//Tricks of the trade : Some bit indexing to check wrapping
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <bitset>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cases;
	long long num;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> num;
		bitset<32> line(num);
		bitset<32> check;
		//check the binary string for each number and add it to the check bitset
		//check the wrapping edges used modulos
		for (int j = 0; j < 32; j++) {
			check.set(16 * line[j] + 8 * line[(j + 1) % 32] + 4 * line[(j + 2) % 32] + 2 * line[(j + 3) % 32] + line[(j + 4) % 32]);
		}
		//check if the check bitset contains all numbers
		if (check.count() == 32) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}