//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Area : 10589 : Brayzen
//
//Data structure required : 
//
//Tricks of the trade : 
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	double N, a;
	while (cin >> N >> a && N != 0) {
		double x, y, A;
		double M = 0;
		for (int i = 0; i < N; i++) {
			bool in = true;
			cin >> x >> y;
			//check the distance from each corner
			if (sqrt(pow(x, 2) + pow(y, 2)) > a) {
				in = false;
			}
			if (sqrt(pow(x, 2) + pow(y-a, 2)) > a) {
				in = false;
			}
			if (sqrt(pow(x-a, 2) + pow(y, 2)) > a) {
				in = false;
			}
			if (sqrt(pow(x-a, 2) + pow(y-a, 2)) > a) {
				in = false;
			}
			//increment M if its within
			if (in) {
				M++;
			}
		}
		//calculate A
		A = M * a * a / N;
		//output with proper decimal places
		cout << fixed << setprecision(5) << A << "\n";
	}
	return 0;
}