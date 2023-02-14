#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> vec[101];
int head[101];
pair<int, int> computers[101];
int N;
int visited[101];
void TSort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		int level = computers[i].first;
		for (int j = 1; j <= N; j++) {
			if (computers[j].first == level+1) {
				vec[i].push_back(j);
				head[j]++;
			}
		}

		if (level == 1) {
			q.push(i);
			visited[i] = computers[i].second;
			
		}

	}

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		int time = visited[current];
		for (int i = 0; i < vec[current].size(); i++) {
			int next = vec[current][i];
			head[next]--;
			int aftertime = time + ((current - next) * (current - next))+computers[next].second;
			if (visited[next] < aftertime) {
				visited[next] = aftertime;
			}

			if (head[next] == 0) {
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
		int a, b;
		cin >> a >> b;
		computers[i] = { a,b };

	}
	TSort();
	int maxvalue = 0;
	for (int i = 1; i <= N; i++) {
		if (maxvalue < visited[i]) {
			maxvalue = visited[i];
		}
	}
	cout << maxvalue;
}