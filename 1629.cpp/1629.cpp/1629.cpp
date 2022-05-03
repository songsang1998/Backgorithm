#include<iostream>
using namespace std;


long long fPow(long long s, long long n, long long C) {
	if (n == 1) {
		return s%C;
	}
	else {
		long long x = fPow(s, n / 2,C) % C;
		if (n % 2 == 0) {
			return (x * x)%C ;
		}
		else {
			return (((x * x)%C)* s)% C;
		}
	}
}
int main() {
	long long A, B, C;
	cin >> A >> B >> C;
	
	cout << fPow(A, B,C)% C;
}