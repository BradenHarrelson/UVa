//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Sin Cos Problem : 12575 : Brayzen
//
//Data structure required :
//
//Tricks of the trade : atan2 -> uses all 4 quadrants by looking at
//cos to see when its negative, when it is, it adds pi
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cases;
	double A, B, angle, max;
	double pi = acos(-1);
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> A >> B;
		max = sqrt(pow(A, 2) + pow(B, 2)); //find the max value
		//Must have answer in first quadrant
		//both positive, simple case
		if (A >= 0 && B >= 0) {
			angle = atan2(A, B); 
		}
		//sin is neg, add 2pi to fix
		else if (A <= 0 && B >= 0) {
			angle = atan2(A, B) + 2 * pi;
		}
		//cos is negative, atan2 handles neg cos
		else if (A >= 0 && B <= 0) {
			angle = atan2(A, B);
		}
		//both sin and cos neg, atan2 handles cos, add 2pi for sin
		else {
			angle = atan2(A, B) + 2 * pi;
		}
		cout << fixed << setprecision(2) << angle << " " << max << "\n";
	}
	return 0;
}