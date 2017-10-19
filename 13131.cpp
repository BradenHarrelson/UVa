//////////////////////////////////////////////////////////////////////
//
//Braden Harrelson : Divisors : 13131 : Brayzen
//
//Data structure required : 
//
//Tricks of the trade : 
//
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using namespace std;
typedef long long ll;
ll _sieve_size;
bitset<10000010> bs;
vector<int> primes;
//used to make prime number table
void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
		for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}
long long SumDivisors(long N) {
	long idx = 0, PF = primes[idx], ans = 1, ct = 0;
	while (PF * PF <= N) {
		long power = 0;
		while (N % PF == 0) {
			N /= PF;
			power++;
		}
		ans *= ((long long)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++idx];
	}
	if (N != 1) ans *= ((long long)pow((double)N, 2.0) - 1) / (N - 1);
	return  ans;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int cases;
	long N, K;
	long long ans;
	sieve(1000);
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> N >> K;
		if (N % K == 0) {
			cout << SumDivisors(N) - K * SumDivisors(N / K) << '\n';
		}
		else {
			cout << SumDivisors(N) << '\n';
		}
	}
	return 0;
}