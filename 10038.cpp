//////////////////////////////////////////////////////////////////////
//
// Braden Harrelson : Jolly Jumpers : 10038 : Brayzen
//
//Data structure required : Vectors
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<cmath>
#define endl "\n"
using namespace std;
void JollyJumper(int n);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		JollyJumper(n);
	}
	return 0;
}
void JollyJumper(int n) {
	vector<bool> isJolly(n - 1, false);
	vector<int> nums;
	bool jolly = true;
	int num1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		nums.push_back(x);
	}
	for (int i = 0; i < n - 1; i++) {
		num1 = abs(nums[i] - nums[i + 1]);
		if (num1 < n && num1 != 0) {
			isJolly[num1 - 1] = true;
		}
		else {
			continue;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (isJolly[i] == false) {
			jolly = false;
		}
	}
	if (jolly == false) {
		cout << "Not jolly" << endl;
	}
	else {
		cout << "Jolly" << endl;
	}
}