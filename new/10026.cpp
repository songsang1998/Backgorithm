#include<iostream>
#include<queue>
using namespace std;
#define pii pair<int,int>
queue <pii> BFSqueue;
char normal[102][102];
char strange[102][102];

bool visted[102][102];

int xarr[4] = { -1,1,0,0 };
int yarr[4] = { 0,0,1,-1 };
void BFS(int x, int y, char(*arr)[102]) {

	BFSqueue.push(make_pair(x, y));
	visted[x][y] = true;

	while (!BFSqueue.empty()) {
		pii temp = BFSqueue.front();
		BFSqueue.pop();
		for (int i = 0; i < 4; i++) {
			int newx = temp.first + xarr[i];
			int newy = temp.second + yarr[i];
			if (visted[newx][newy] == false) {
				if (arr[x][y] == arr[newx][newy]) {
					visted[newx][newy] = true;
					BFSqueue.push(make_pair(newx, newy));
				}
			}
		}

	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	fill(&visted[0][0], &visted[N + 1][N + 1], false);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char c;
			cin >> c;

			normal[i][j] = c;

			if (c == 'G') {
				c = 'R';
			}
			strange[i][j] = c;
		}
	}
	int num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visted[i][j] == false) {
				BFS(i, j, normal);
				num++;
			}
		}
	}
	cout << num;
	fill(&visted[0][0], &visted[N + 1][N + 1], false);
	num = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (visted[i][j] == false) {
				BFS(i, j, strange);
				num++;
			}
		}
	}
	cout << " " << num;
}