#include<iostream>
#include<memory.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define INF 999999999;
vector<int> v[501];
int N, M;
int visited[501];

void bfs(int start) {
	queue<int> q;

	q.push(start);
	visited[start] = 0;
	while (!q.empty()) {
		int next = q.front();
		q.pop();

		for (int i = 0; i < v[next].size(); i++) {
			int temp = v[next][i];
			if (visited[temp] == -1) {
				q.push(temp);
				visited[temp] = visited[next] + 1;

			}
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(visited, -1, sizeof(visited));


	cin >> N >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int Q;

	cin >> Q;

	for (int q = 0; q < Q; q++) {
		int b, c;
		cin  >> b >> c;
		
			v[b].push_back(c);
			v[c].push_back(b);
			bfs(1);
			for (int i = 1; i <= N; i++) {
				if (i != 1) {
					cout << " ";
				}
				cout << visited[i];
			}
			cout << '\n';
			memset(visited, -1, sizeof(visited));
		
		
	}

}