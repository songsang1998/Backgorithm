#include<iostream>
#include<vector>
#include<memory.h>

using namespace std;
bool visited[500001];
vector<int> vec[500001];
long long sum = 0;
void DFS(int start, int depth) {

	visited[start] = true;


	if (vec[start].size() == 1 && start != 1) {
		sum += depth;
		return;
	}

	for (int i = 0; i < vec[start].size();i++) {
		int next = vec[start][i];
		if (!visited[next]) {
			visited[next] = true;
			DFS(next,depth+1);
			
		}
	}

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	DFS(1,0);

	if (sum % 2 == 0) {
		cout << "No";
	}
	else {
		cout << "Yes";
	}
}