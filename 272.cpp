//Braden Harrelson

#include <iostream>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	string line;
	bool flag = true;
	while(getline(cin, line)){
		for (int i = 0; i < line.length(); i++){
			if (line[i] == '"' && flag){
				line.replace(i, 1, "``");
				flag = !flag;
			}
			else if(line[i] == '"' && !flag){
				line.replace(i, 1, "''");
				flag = !flag;
			}
		}
		cout << line << '\n';
	}
	return 0;
}
