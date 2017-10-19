//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : CD : 11849 : Brayzen
//
//Data structure required : Sets, vector
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int numJack, numJill, temp;
	//read in until 0 0
	while (cin >> numJack >> numJill && numJack != 0 && numJill != 0) {
		set<int> jack, jill;
		vector<int>::iterator it;
		//vector to hold intersections
		vector<int> common(1000000);
		for (int i = 0; i < numJack; i++) {
			cin >> temp;
			jack.insert(temp);
		}
		for (int i = 0; i < numJill; i++) {
			cin >> temp;
			jill.insert(temp);
		}
		//find intersection
		it = set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), common.begin());
		//resize vector for number of actual intersections
		common.resize(it - common.begin());
		cout << common.size() << "\n";
	}
	return 0;
}