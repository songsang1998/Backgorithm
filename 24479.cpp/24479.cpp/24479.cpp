#include<iostream>
#include<vector>
#include<algorithm>

#include<memory.h>
using namespace std;


vector<int> vec[500001];
bool visited[500001];
int order[500001];
int current = 0;
void DFS(int start) {
	
		visited[start] = true;
		current++;
		order[start] = current;

		for (int i = 0; i < vec[start].size(); i++) {
			int next = vec[start][i];
			if (!visited[next]) {
				DFS(next);
			}
			}
		


}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	current= 0;
	int N, M, R;
	memset(visited, false, sizeof(visited));

	cin >> N>> M>>R;



	for (int m = 0; m < M; m++) {
		int q, w;
		cin >> q >> w;

		vec[q].push_back(w);
		vec[w].push_back(q);
	}


	for (int n = 1; n <= N; n++) {
		sort(vec[n].begin(), vec[n].end());
		
	}
	DFS(R);

	for (int n = 1; n <= N; n++) {
		cout <<  order[n]<<'\n';
	}
}