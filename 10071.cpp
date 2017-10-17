#include <iostream>

using namespace std;
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
	int num1, num2;
	while (cin >> num1) {
		cin >> num2;
		cout << num1 * num2 * 2 << '\n';
	}
    return 0;
}
