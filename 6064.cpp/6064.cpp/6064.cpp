#include<iostream>

using namespace std;

long long gcd(int A, int B) {

	long long c = A % B;

	if (c != 0) {
		return gcd(B, c);
	}
	else {
		return B;
	}
}


int main() {
	

	int T;
	cin >> T;
	



	for (int t = 0; t < T; t++) {
		
		long long N;
		long long M;
		long long x;
		long long y;
		cin >> N;
		cin >> M;
		cin >> x;
		cin >> y;
	

		long long r = gcd(N, M);
		long long max = (N * M) / r;
		int sum = -1;
		for (int i = x; i <= max;) {
			if (i % M == y%M) {
				sum = i;
				break;
			}

			i += N;
		}

		cout << sum << "\n";
	}
	return 0;
}