#include<iostream>

using namespace std;

int GCD(int a, int b) {

	int c = a % b;

	if (c==0) {
		return b;
	}
	else {
		return GCD(b, c);
	}
}

int LCM(int a, int b,int c) {
	return a * b / c;
}

int main() {

	int N;
	int M;
	cin >> N >> M;
	int v = GCD(N, M);
	cout << v << "\n";
	cout << LCM(N, M, v)<<"\n";
	

}