#include<iostream>
#include<memory.h>
#include<vector>
#include<cmath>
#include<queue>
#define INF 0x3f3f3f3f

using namespace std;


int visited[3000001];
vector < int> v[3000001];
int N, M;
int S, E;


void BFS(int start,int k) {
	
	queue<pair<int,int>> q;
	q.push(make_pair(start,k));
	visited[start] = k;
	
	while (!q.empty()) {

		
		
		int next = q.front().first;
		int temp = q.front().second;
		
		q.pop();

		if (next == E) {
			cout << temp;
		}

		if (visited[next+1]== -1 && next !=N) {
			q.push(make_pair(next+1,temp+1));
			visited[next+1] = temp+1;
		}
		if (visited[next - 1] == -1 && next != 1) {
			q.push(make_pair(next - 1, temp + 1));
			
			visited[next - 1] = temp + 1;
		}

		for (int i = 0; i < v[next].size(); i++) {
			int tempnext = v[next][i];

			if (visited[tempnext] == -1 ) {
				q.push(make_pair(tempnext, temp + 1));
				visited[tempnext] = temp + 1;
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
	
	cin >> S >> E;

	for (int m = 0; m < M; m++) {
		int a, b;
		cin >> a>> b;
		v[a].push_back(b);
		v[b].push_back(a);

	}
	

	BFS(S, 0);
	
}