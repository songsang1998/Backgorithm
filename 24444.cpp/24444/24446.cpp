#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;

vector<int> v[100001];
queue<int> q;
int result[100001];
int visited[100001];
void BFS(int start) {
	memset(visited, false, sizeof(visited));
	visited[start] = true;

	q.push(start);
	int depth = 0;
	result[start] = depth;
	while (!q.empty()) {
		int r = q.front();
		q.pop();

		for (int i = 0; i < (int)v[r].size(); i++) {
			int next = v[r][i];

			if (visited[next] == false) {

				result[next] = result[r] + 1;

				q.push(next);
				visited[next] = true;
			}
		}

	}
}


int main(void) {
	int N, M, R;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> N >> M >> R;
	memset(result, -1, sizeof(result));

	for (int m = 0; m < M; m++) {
		int X, Y;
		cin >> X >> Y;
		v[X].push_back(Y);
		v[Y].push_back(X);
	}

	BFS(R);

	for (int i = 1; i <= N; i++) {
		cout << result[i] << "\n";
	}
}