#include<iostream>
#include<vector>
#define pii pair<int,int>
using namespace std;

vector<pii> a[10001];
int visted[10001];
pii mp;
void DFS(int N) {

	

	for (int i = 0; i < a[N].size(); i++) {
		int with = a[N][i].first;
		if (visted[with] == 0) {
			visted[with] = a[N][i].second+visted[N];
			if (visted[with] > mp.first) {
				mp.first = visted[with];
				mp.second = with;
			}
			DFS(with);
			
		}
	}
}

int main() {
	mp = { 0,0 };
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a1, a2, a3;
		cin >> a1 >> a2 >> a3;

		a[a1].push_back({ a2,a3 });
		a[a2].push_back({ a1,a3 });
	}`
	visted[1] = 1;
	DFS(1);
	fill(&visted[0], &visted[10001], 0);
	
	mp.first=1;
	visted[mp.second] = 1;
	DFS(mp.second);

	cout << mp.first-1;
}