#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>
using namespace std;
int visited[10001];
pair<int,int> timeTable[10001];
vector<int> vec[10001];

int N;
void Tsort() {
	queue<int> q;
		
	for (int i = 1; i <= N; i++) {
		if (timeTable[i].second == 0) {
			q.push(i);
			visited[i]=timeTable[i].first;
		}
	}

	while (!q.empty()) {
		int current = q.front();
		q.pop();

		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i];
			if (visited[current] + timeTable[next].first > visited[next]) {
				visited[next] = visited[current] + timeTable[next].first;
			}
			timeTable[next].second--;

			if (timeTable[next].second == 0) {
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

	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		timeTable[i].first = a;

		int b;
		cin >> b;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			vec[c].push_back(i);
			timeTable[i].second++;
		}

	}
	Tsort();
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max < visited[i]) {
			max = visited[i];
		}
	}
	cout << max;
}