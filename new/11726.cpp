#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	long arr[1001];
	arr[1] = 1;
	arr[2] = 2;
	if (N >= 3) {
		for (int i = 3; i <= N; i++) {
			arr[i] = (arr[i - 2] + arr[i - 1]) % 10007;
		}
		cout << arr[N];
	}
	else {
		cout << arr[N];
	}
}