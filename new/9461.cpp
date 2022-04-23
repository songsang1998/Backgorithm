#include<iostream>
using namespace std;
int main() {
	int N;
	long long fi[100] = { 1,1,1,2,2 };
	int T;
	cin >> T;

	for (int i = 5; i < 100; i++) {
		fi[i] = fi[i - 5] + fi[i - 1];
	}
	for (int t = 0; t < T; t++) {
		cin >> N;
		cout << fi[N - 1] << endl;;
	}
}