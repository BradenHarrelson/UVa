//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : One Little, Two Little, Three Little Endians : 594 : Brayzen
//
//Data structure required : Bitsets
//
//Tricks of the trade : Handling negatives bitsets with int casting
//
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<bitset>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num;
	while (cin >> num){
		bitset<32> oldBit(num);
		bitset<32> newBit;
		//transfer a byte at a time to new bitset in opposite order
		for (int i = 0; i < 32; i++){
			newBit[32 - ((i / 8 + 1) * 8) + (i % 8) ] = oldBit[i];
		}
		//output. Casting as int accounts for the negatives
		cout << (int)oldBit.to_ulong() << " converts to "<< (int)newBit.to_ulong() << "\n";
	}
	return 0;
}