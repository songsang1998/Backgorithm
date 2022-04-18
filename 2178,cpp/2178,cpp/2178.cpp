#include<iostream>
#include <queue>
#include<memory.h>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
int arr[102][102];
int visted[102][102];
queue<pii> qq;
void BFS(int a, int b){
	for (int i = 0; i < 102; i++) {
		memset(visted[i], 0, sizeof(arr[i]));
	}
	visted[1][1] += 1;
	pii px;
	px.F = 1;
	px.S = 1;
	qq.push(px);

	while (!qq.empty()) {
		pii tempp = qq.front();
		if (tempp.F == a) {
			if (tempp.S == b) {
				cout << visted[a][b];
				break;
			}
		}
		qq.pop();
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int tempi = i;
				int tempj = j;
				if (tempi == 0 && tempj == 0) {
					tempj = -1;
				}
				else if (tempi == 1 && tempj == 1) {
					tempi = -1;
					tempj = 0;
				}
				
				if (visted[tempp.F+tempi][tempp.S+tempj] == 0) {
					if (arr[tempp.F+tempi][tempp.S+tempj] == 1) {
						visted[tempp.F + tempi][tempp.S+tempj] = visted[tempp.F][tempp.S]+1;
						pii tempa;
						tempa.F = tempp.F + tempi;
						tempa.S = tempp.S + tempj;
						qq.push(tempa);
					}
				}

			}
		}

	}
}




int main() {
	for (int i = 0; i < 102; i++) {
		memset(arr[i], 0, sizeof(arr[i]));

	}
	int N;
	int M;
	cin >> N;
	cin >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char a;
			cin >> a;
			arr[i][j] = a-'0';

		}
	}
	BFS(N, M);
	
}