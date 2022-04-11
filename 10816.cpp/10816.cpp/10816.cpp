#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	int M;
	cin >> N;
	int arr[500001];
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	sort(arr, arr + N);
	cin >> M;
	int B=0;
	int F=0;
	
	
	for (int i = 0; i < M; i++) {
		long long start = 0;
		long long end = N;
		end--;
		
		int a;
		cin >> a;
		while (start <= end) {
			long long mid = (start + end) / 2;

			if (a > arr[mid]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}

		}
		

		F = start;

		start = 0;
		end = N;
		end--;
		while (start <= end) {
			long long mid = (start + end) / 2;

			if (a >= arr[mid]) {
				start = mid + 1;
			}
			else {
				end = mid - 1;
			}
		}

		B = end;
		
		if (arr[B]==a || arr[F] ==a) {
			B += 1;
			cout << B - F << " " ;
		}
		else {
			cout << 0 << " " ;
		}
	}
	
}