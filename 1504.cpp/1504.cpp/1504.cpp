#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
#define INF 200000000
using namespace std;

vector<pii> arr[801];
int visted[801];

void distra(int src) {
	
	priority_queue<pii> pq;
	pq.push({ 0,src });
	fill(&visted[0], &visted[801], INF);
	visted[src] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int with = pq.top().second;
		pq.pop();
		 
		for (int i = 0; i < arr[with].size(); i++) {
			int next = arr[with][i].first;
			int nextcost = arr[with][i].second + cost;
			if (visted[next] >= nextcost) {
				visted[next] = nextcost;
				pq.push({ nextcost,next });
			}
		}


	}

}

int main() {                                                                   
	int N;
	int M;

	cin >> N;
	cin >> M;
	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		arr[b].push_back({ a,c });
	}
	int v1, v2;
	cin >> v1;
	cin >> v2;

	distra(1);
	int tempone = visted[v1];
	distra(v1);
	int temptwo = visted[v2];
	distra(v2);
	int tempthree = visted[N];

	int m1 = tempone + temptwo+ tempthree;

	distra(1);
	tempone = visted[v2];
	distra(v2);
	temptwo = visted[v1];
	distra(v1);
	tempthree = visted[N];
	int m2 = tempone + temptwo + tempthree;

	int mins= min(m1, m2);
	if (mins >= INF) {
		cout << -1;
	}
	else {
		cout << mins;
	}
}                                              