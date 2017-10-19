//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Google is Feeling Lucky : 12015 : Brayzen
//
//Data structure required : Vectors, String.
//
//Tricks of the trade :
//
/////////////////////////////////////////////////////////////////////

#include<iostream>
#include<string>
#include<vector>
#define endl "\n"
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		vector<string> pages;
		int relavance = 0;
		for (int j = 0; j < 10; j++){
			string website;
			int num;
			cin >> website;
			cin >> num;
			if (num > relavance){
				pages.clear();
				pages.push_back(website);
				relavance = num;
			}
			else if (num == relavance){
				pages.push_back(website);
			}
		}
		int s = pages.size();
		cout << "Case #" << i + 1 << ":" << endl;
		for (int k = 0; k < s; k++){
			cout << pages[k] << endl;
		}
	}

	return 0;
}