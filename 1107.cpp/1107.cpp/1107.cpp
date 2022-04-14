#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	bool arr[10];
	int M;
	
	cin >> M;


	for (int i = 0; i < 10; i++) {

		arr[i] = true;
	}


	for (int i = 0; i < M; i++) {
		int s;
		cin >> s;

		arr[s] = false;
	}
	bool skip = false;
	int sum = 0;
	int min = 10000000;
	for (int i = 0; i <= 999999; i++) {
		
		sum = 0;
		int a = i;
		skip = false;
		if (i != 100) { 
			sum++;
		}
		if (i != 100) {
			while (a >= 10) {
				sum++;
				if (sum >= min) {
					skip = true;
					break;
				}
				int c = a % 10;
				if (arr[c] == false) {
					skip = true;
					break;
				}

				a /= 10;
			}
			if (skip == false && arr[a] == false) {
				skip = true;
			}
			
		}
		

		if (skip == false) {
			if (i > N) {
				sum += i - N;
			}
			else if (i < N) {
				sum += N-i;
			}
			
			if (sum < min) {
				min = sum;
			}

		}
	}

	cout << min;
}
