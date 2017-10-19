//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Parentheses Balance : 673 : Brayzen
//
//Data structure required : Stack, string
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);//speed
	int cases;
	string line;
	bool balanced = true;
	cin >> cases; //get number of lines
	cin.ignore();
	//read in lines
	for (int i = 0; i < cases; i++) {
		getline(cin, line);
		if (line.length() > 0) { //default to true if empty string
			stack<char> pStack;
			//if open push
			for (int j = 0; j < line.length(); j++) {
				if (line[j] == '(' || line[j] == '[') {
					pStack.push(line[j]);
				}
				//else check for balance and pop if needed
				else if (line[j] == ')') {
					if (pStack.empty() || pStack.top() != '(') {
						balanced = false;
						break;
					}
					else {
						pStack.pop();
					}
				}
				else if (line[j] == ']') {
					if (pStack.empty() || pStack.top() != '[') {
						balanced = false;
						break;
					}
					else {
						pStack.pop();
					}
				}
			}
			//if not empty at this point, not balanced
			if (!pStack.empty()) {
				balanced = false;
			}
		}
		//output
		if (balanced) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
			balanced = true;
		}
	}
	return 0;
}