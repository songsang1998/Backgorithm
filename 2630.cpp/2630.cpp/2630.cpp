#include<iostream>
using namespace std;

int N;
int arr[129][129];

int white;
int blue;

void Paper(int N, int x, int y) {
	int sum = 0;
	for (int i = x; i <= N+x-1; i++) {
		for (int j = y; j <= N+y-1; j++) {
			sum += arr[i][j];
			
		}
	}

	if (sum == 0) {
		white+=1;
		return;
	}
	else if (sum == N*N) {
		blue+=1;
		return;
	}
	else {
		for (int i = 0; i <= 1; i++) {
			for (int j = 0; j <= 1; j++) {
				Paper(N / 2, x + ((N / 2 * i )), y + ((N / 2 * j)));
			}
		}
		return;
	}
}


int main() {
	white = 0;
	blue = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			cin >> a;
			arr[i][j] = a;
		}
	}
	Paper(N,1,1);

	cout << white << "\n";
	cout << blue << "\n";
}