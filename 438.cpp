//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : The Circumference of a circle : 438 : Brayzen
//
//Data structure required : Pairs
//
//Tricks of the trade : Heron's Formula
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <utility>
#include <math.h>
#include <iomanip>
using namespace std;
//calculates distance between points
double dist(pair<double, double> a, pair<double, double> b){
	double distance = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
	return distance;
}
//returns area of triangle
double area(double ab, double bc, double ca){
	double s = (ab + bc + ca) / 2;
	double a = sqrt(s*(s - ab) * (s - bc) * (s - ca));
	return a;
}
//return radius from here
double rCircumCircle(double ab, double bc, double ca){
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
//pass 3 pairs here for radius
double rCircumCircle(pair<double, double> a, pair<double, double> b, pair<double, double> c){
	return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	pair<double, double> a, b, c;
	while (cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second){
		double radius = rCircumCircle(a, b, c);
		//2*pi*r = radius
		cout << fixed << setprecision(2) << 2.0 * acos(-1) * radius << "\n";
	}
	return 0;
}