//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Wetlands of Florida : 469 : Brayzen
//
//Data structure required : Vector, string
//
//Tricks of the trade : Peeking data to see its type. isaplha/isdigit
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
using namespace std;
int GetWater(vector<vector<char> > &map, int x, int y) {
	//if L return instantly
	if (map[x][y] == 'L') {
		return 0;
	}
	//replace and check neighbors
	else {
		map[x][y] = 'L';
		return 1 + GetWater(map, x + 1, y) + GetWater(map, x, y + 1)
			+ GetWater(map, x - 1, y) + GetWater(map, x, y - 1)
			+ GetWater(map, x + 1, y + 1) + GetWater(map, x + 1, y - 1)
			+ GetWater(map, x - 1, y + 1) + GetWater(map, x - 1, y - 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cases;
	string line;
	// >> ws will read in the white space
	cin >> cases >> ws;
	for (int i = 0; i < cases; i++) {
		int x, y, numWater;
		int l = 1;
		vector<vector<char> > map(101, vector<char>(101, 'L'));
		vector<vector<char> > map2; //used for each check
		while (isalpha(cin.peek())) {
			cin >> line >> ws;
			for (int j = 1; j < line.size() + 1; j++) {
				map[l][j] = line[j - 1];
			}
			l++;
		}
		//map is filled now read in points to test
		while (isdigit(cin.peek())) {
			cin >> x >> y >> ws;
			map2 = map; //reset the map
			numWater = GetWater(map2, x, y);
			cout << numWater << "\n";
		}
		//preventing one too many new lines
		if (i < cases - 1) {
			cout << "\n";
		}
		//read to next map
		cin >> ws;
	}
	return 0;
}