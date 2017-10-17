#include <iostream>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
	long long num1, num2;
	while (cin >> num1) {
		cin >> num2;
		long long dif;
		if (num1 > num2){
		  dif = num1 - num2;
		}
		else{
		  dif = num2 - num1;
		}
		cout << dif << '\n';
	}
    return 0;
}
