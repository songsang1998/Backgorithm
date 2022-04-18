#include<iostream>
using namespace std;

int arr[66][66];
int N;
void QuadTree(int max, int x,int y) {
	
	int sum = 0;
	for (int i = x; i <= x+max-1; i++) {
		for (int j = y; j <= y+max-1; j++) {
			sum += arr[i][j];
		}
	}

	if (sum == 0) {
		cout << "0";
	}
	else if (sum == max*max) {
		cout << "1";
	}
	else {
		cout << "(";
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				
				QuadTree(max / 2, x + (max/2 * i), y + (max/2 * j));
				
			}
		}
		cout << ")";
	}
	
}



int main() {
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char temp;
			cin >> temp;
			arr[i][j] = temp-'0';
		}
	}

	QuadTree(N, 1, 1);
	
}