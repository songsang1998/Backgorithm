#include<iostream>
#include<queue>
using namespace std;
#define pii pair<int,int>


int arr[102][102];

queue <pii> pque;



int main() {
	
	int N;
	cin>>N;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
			
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][k] == 1 && arr[k][j] == 1) {
				
					arr[i][j] = 1;
				}

			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j];
			if (j != N) {
				cout << " ";
			}
		}
		cout << "\n";
	}
}