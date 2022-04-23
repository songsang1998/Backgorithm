#include <iostream>
#include<queue>
using namespace std;

vector<int> qa[1002];
bool visted[1002];
void DFS(int x) {
	queue<int> check;
	visted[x] = true;
	check.push(x);
	while (!check.empty()) {
		int o = check.front();
		check.pop();
		for (int i = 0; i < qa[o].size(); i++) {
			if (visted[qa[o][i]] == false) {
				visted[qa[o][i]] = true;
				check.push(qa[o][i]);
			}
		}
	}
}



int main() {
	int N;
	cin >> N;
	int M;
	cin >> M;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a >> b;
		qa[a].push_back(b);
		qa[b].push_back(a);
	}
	int num = 0;
	for (int i = 1; i <= N; i++) {
		if (visted[i] == false) {
			DFS(i);
			num++;
		}
	}
	cout << num;
}