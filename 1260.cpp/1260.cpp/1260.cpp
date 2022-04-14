#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<memory.h>
using namespace std;


bool temp[1001];
vector<int> Nlist[1001];
queue<int> que;

void DFS(int v) {
	temp[v] = true;
	cout << v <<" ";
	for (int i = 0; i < Nlist[v].size(); i++) {
		int t = Nlist[v][i];
		if (temp[t] == false) {
			DFS(t);
		}
	}


}

void BFS(int v) {
	
	memset(temp, false, 1001);
	
	temp[v] = true;
	que.push(v);

	cout << v;

	while (!que.empty()) {
		int s = que.front();
		que.pop();
		
		for (int i = 0; i < Nlist[s].size(); i++) {
			
			int tem = Nlist[s][i];
			
			if (temp[tem] == false) {
				
				que.push(tem);
				temp[tem] = true;

				cout <<" "<< tem ;
			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	memset(temp, false, 1001);
	int N;
	int M;
	cin >> N;
	cin >> M;
	int V;
	cin >> V;
	for (int i = 0; i < M; i++) {
		int L, R;
		cin >> L >> R;

		Nlist[L].push_back(R);
		Nlist[R].push_back(L);
	}
	for (int i = 0; i < 1001; i++) {
		sort(Nlist[i].begin(), Nlist[i].end());
	}
	
	DFS(V);
	cout << "\n";
	BFS(V);
	
}