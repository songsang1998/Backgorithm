#include<iostream>

using namespace std;
int arr[100001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	int M;
	cin >> N;
	cin >> M;
	for (int n = 0; n < N; n++) {
		int k;
		cin >> k;
		if (n == 0) {
			arr[n] = k;
		}
		else {
			arr[n] = arr[n - 1] + k;
		}

	}
	for (int m = 0; m < M; m++) {
		int i;
		int j;
		cin >> i;
		cin >> j;

		if (i == 1) {
			cout << arr[j - 1] << "\n";
		}
		else {
			cout << arr[j - 1] - arr[i - 2] << "\n";
		}


	}
}