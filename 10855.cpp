//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Rotated Squares : 10855 : Brayzen
//
//Data structure required : Vectors
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;
void rotate(vector<vector<char>>&, int);
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int sizeBig, sizeSmall;
	while (cin >> sizeBig && cin >> sizeSmall) {
		if (sizeBig == 0) {
			break;
		}
		vector<vector<char>> big(sizeBig, vector<char>(sizeBig));
		vector<vector<char>> small(sizeSmall, vector<char>(sizeSmall));
		//insert big square
		for (int i = 0; i < sizeBig; i++) {
			for (int k = 0; k < sizeBig; k++) {
				cin >> big[i][k];
			}
		}
		//insert small square
		for (int i = 0; i < sizeSmall; i++) {
			for (int k = 0; k < sizeSmall; k++) {
				cin >> small[i][k];
			}
		}
		//check and then rotate after each check
		for (int y = 0; y < 4; y++) {
			int matches = 0;
			for (int s = 0; s <= sizeBig - sizeSmall; s++) {
				for (int f = 0; f <= sizeBig - sizeSmall; f++) {
					bool check = true;
					for (int i = 0; i < sizeSmall; i++) {
						for (int k = 0; k < sizeSmall; k++) {
							if (big[i + s][k + f] != small[i][k]) {
								check = false;
								break;
							}
						}
					}
					if (check) {
						matches++;
					}
				}
			}
			if (y != 3) {
				cout << matches << " ";
			}
			else {
				cout << matches;
			}
			rotate(small, sizeSmall);
		}
		cout << "\n";
	}
	return 0;
}
void rotate(vector<vector<char>> &square, int size) {
	vector<char> temp;
	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= 0; j--) {
			temp.push_back(square[j][i]);
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			square[i][j] = temp[size*i + j];
		}
	}
}