//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Sudoku : 13115 : Brayzen
//
//Data structure required : Vector, set
//
//Tricks of the trade : Using a set to check for duplicates
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cases, size, temp;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> size;
		vector<vector<int> > sudoku(size, vector<int>(size));
		set<int> checkLine;
		pair<set<int>::iterator, bool> ret;
		bool isValid = true;
		//read in puzzle
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				cin >> sudoku[j][k];
			}
		}
		//now check if valid
		//check rows first
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				ret = checkLine.insert(sudoku[j][k]);
				if (ret.second == false) {
					isValid = false;
				}
			}
			checkLine.clear();
		}

		//check columns
		if (isValid){
			for (int j = 0; j < size; j++) {
				for (int k = 0; k < size; k++) {
					ret = checkLine.insert(sudoku[k][j]);
					if (ret.second == false) {
						isValid = false;
					}
				}
				checkLine.clear();
			}
		}
		//check squares
		//checking sqrt(size) x sqrt(size) sub squares
		if (isValid) {
			int subSquare = sqrt(size);
			for (int j = 0; j < subSquare; j++) {
				for (int k = 0; k < subSquare; k++) {
					for (int p = subSquare * j; p < subSquare * j + subSquare; p++) {
						for (int l = subSquare * k; l < subSquare * k + subSquare; l++) {
							ret = checkLine.insert(sudoku[p][l]);
							if (ret.second == false) {
								isValid = false;
							}
						}
					}
					checkLine.clear();
				}
			}
		}
		//output
		if (isValid) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}