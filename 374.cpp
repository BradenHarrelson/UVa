//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Big Mod : 374 : Brayzen
//
//Data structure required : 
//
//Tricks of the trade : modified exponent function
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
//fast exponent function from green book with added % m
long modExp(long base, long p, long m){
	//normal base cases for exponents
	if (p == 0) return 1 % m;
	else if (p == 1) return base % m;
	//recursive calls when not at base case
	else{
		//call with p/2 till base case
		long long res = modExp(base, p / 2, m);
		//square each call
		res *= res;
		//if odd, multiply again
		if (p % 2 == 1) res *= base;
		return res % m;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	long b, p, m, r;
	while (cin >> b >> p >> m){
		//call function for each case and output
		r = modExp(b, p, m);
		cout << r << "\n";
	}
	return 0;
}