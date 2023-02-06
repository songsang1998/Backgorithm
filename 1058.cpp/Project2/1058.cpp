#include <iostream>

using namespace std;

const int INF = 9999999;
int arr[51][51];

int N;

void FloydFunction(){
	for (int k= 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (i == k || j == k || i == j) {

				}
				else {
					int temp = arr[i][k] + arr[k][j];
					if (temp < arr[i][j]) {
						arr[i][j] = temp;
					}
				}
			}
		}

	}
}

int main(void) {


	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char t;
			cin >> t;
			if (t == 'N') {
				arr[i][j] = INF;
			}
			else if (t == 'Y') {
				arr[i][j] = 1;
			}

		}
	}
	FloydFunction();

	int max = 0;
	for (int i = 1; i <= N; i++) {
		int check = 0;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] <= 2) {
				check++;
			}
		}
		
		if (check > max) {
			max = check;
		}
		
	}

	cout << max;
}