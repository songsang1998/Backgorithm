#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int DP[301];



int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int ca;
		cin >> ca;
		arr[i] = ca;
	}
	

	DP[0] = arr[0];
	DP[1] = max(arr[1], arr[0] + arr[1]);
	DP[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < N; i++) {
		DP[i] = max(arr[i] + DP[i - 2], arr[i] + arr[i - 1] + DP[i - 3]);
	}



	
	cout << DP[N-1];
}