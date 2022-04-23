#include<iostream>
#include<algorithm>
using namespace std;
int arr[1001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int s;
		cin >> s;
		arr[n] = s;
	}
	int sum = 0;
	sort(arr, arr + N);
	for (int n = 0; n < N; n++) {
		arr[n + 1] += arr[n];
		sum += arr[n];
	}
	cout << sum;
}