#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>


using namespace std;

queue<int> pque;
int arr[101];
int visted[101];

void BFS(int start) {
	pque.push(start);
	visted[start] = 0;

	while (!pque.empty()) {
		int x = pque.front();
		
		pque.pop();

		for (int i = 1; i <= 6; i++) {
			int k = x + i;
			if (k <= 100) {
				if (arr[k] != 0) {
					k = arr[k];
				}
				if (visted[k] > visted[x]+1) {
					visted[k] = visted[x] + 1;
					pque.push(k);
				}
			}
		}
	}
}


int main() {
	int N;
	int M;
	

	cin >> N;
	cin >> M;

	fill(&visted[0], &visted[101], 999999);

	for (int n = 1; n <= N; n++) {
		int x;
		cin >> x;
		int y;
		cin >> y;
		arr[x] = y;
	}

	for (int m = 1; m <= M; m++) {
		int x;
		cin >> x;
		int y;
		cin >> y;
		arr[x] = y;
	}
	BFS(1);
	cout << visted[100];
}