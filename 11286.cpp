//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Conformity : 11286 : Brayzen
//
//Data structure required : Maps, strings, vector
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int num;
	while (cin >> num && num != 0){
		vector<string> course(5);
		string s;
		int biggest, tie;
		map<string, int> classes;
		map<string, int>::iterator it;
		//put input into strings then into a map
		for (int j = 0; j < num; j++){
			for (int i = 0; i < 5; i++){
				cin >> course[i];
			}
			sort(course.begin(), course.end());
			//insert sorted strings into map
			for (int i = 0; i < 5; i++){
				s = s + course[i];
			}
			classes[s]++;
			s.clear();
		}
		//initialize biggest as first element
		biggest = classes.begin()->second;
		tie = 0;
		//loop through and find biggest, account for ties
		for (it = classes.begin(); it != classes.end(); it++){
			if (it->second > biggest){
				biggest = it->second;
				tie = 1;
			}
			else if (it->second == biggest){
				tie++;
			}
		}
		//set tie to equal total number of biggests if present
		if (tie != 0) {
			tie = tie * biggest;
		}
		//output result
		if (tie > biggest){
			cout << tie << "\n";
		}
		else{
			cout << biggest << "\n";
		}
	}
	return 0;
}
