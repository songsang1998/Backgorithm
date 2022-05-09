#include<iostream>
#include<queue>

#define pii pair<int,int>

const int INF = 100000001;
using namespace std;

priority_queue<pii,vector<pii>,greater<pii>> pq;

vector<pii> pv[1001];
int visted[1001];
void Distrka(int N) {
	visted[N] = 0;
	pq.push({ 0,N });
	while(!pq.empty()) {
		pii temp = pq.top();
		pq.pop();
		int count = temp.first;
		int w = temp.second;
		if (count <=visted[w]) {
			for (int i = 0; i < pv[w].size(); i++) {
				int Tocount = pv[w][i].second;
				int next = pv[w][i].first;

				if (Tocount + count <visted[next]) {
					visted[next] = Tocount + count;
					pq.push({ Tocount + count, next });
				}
			}
		}
	}
}

int main() {
	int N;
	int M;
	fill(&visted[0], &visted[1001], INF);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		pv[a].push_back({ b,c });
	}
	int X;
	int Y;
	cin >> X >> Y;
	Distrka(X);
	cout << visted[Y];
}