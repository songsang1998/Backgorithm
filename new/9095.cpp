#include<iostream>
using namespace std;


int Num(int N) {
	if (N == 1) {
		return 1;
	}
	else if (N == 2) {
		return 2;
	}
	else if (N == 3) {
		return 4;
	}
	else {
		return Num(N - 3) + Num(N - 2) + Num(N - 1);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int a;
		cin >> a;
		int b = Num(a);
		cout << b << "\n";
	}
}