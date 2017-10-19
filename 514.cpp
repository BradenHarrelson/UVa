//////////////////////////////////////////////////////////////////////
//
//Your name : Rails : 514 : Brayzen
//
//Data structure required : Stacks, queues
//
//Tricks of the trade :Some ASCII manip on cin.peek()
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int numCarts, num, temp;
	while (cin >> numCarts) {
		while (numCarts) {
			stack<int> station;
			queue<int> outgoingCarts;
			//read in outgoing cart order
			for (int i = 0; i < numCarts; i++) {
				cin >> num;
				outgoingCarts.push(num);
			}
			//push and check for tranfer condition
			for (int i = 1; i <= numCarts; i++) {
				station.push(i);
				while (!station.empty() && station.top() == outgoingCarts.front()) {
					station.pop(); outgoingCarts.pop();
				}
			}
			//output results
			if (station.empty()) {
				cout << "Yes\n";
			}
			else {
				cout << "No\n";
			}
			cin.ignore();
			temp = cin.peek(); //check next number on input
			temp = temp - 48;
			if (!temp) {
				cin >> num;
				numCarts = num;
				cout << "\n";
			}
		}
	}
	return 0;
}