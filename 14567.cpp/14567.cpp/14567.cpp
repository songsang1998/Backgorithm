#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> vec[1001];

int degree[1001];
int N;
int visited[1001];
void TSort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0) {
			q.push(i);
			visited[i] += 1;
		}
	}
	
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i];
			degree[next]--;
			if (degree[next] == 0) {
				visited[next] = visited[current] + 1;
				q.push(next);
			}
		}
	}
}



int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	
	cin >> N;
	int M;
	cin >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;

		vec[a].push_back(b);
		degree[b]++;
	}
	TSort();
	for (int i = 1; i <= N; i++) {
		if (i != 1) {
			cout << " ";
		}
		cout << visited[i];
	}
}