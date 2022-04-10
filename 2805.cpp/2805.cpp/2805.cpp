#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	long long M;
	cin >> N >> M;



	int a[1000001];
	int x;
	long long min=0;
	long long max = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		a[i] = x;
		
		if (max < x) {
			max = x;
		}
	}

	max++;

	while (min+1<max) {
		long long mid = (min + max) / 2;

		long long sum = 0;

		for (int i = 0; i < N; i++) {
			if (a[i] > mid) {
				sum += a[i]-mid;
			}
		}

		if (sum >= M) {
			min = mid;
		}
		else {
			max = mid;
		}
	}
	
	cout << min << endl;
}