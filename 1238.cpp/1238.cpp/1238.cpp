#include <iostream>
#include<vector>
#include<queue>

#define INF 1000000
#define pii pair<int,int>
using namespace std;

priority_queue <pii> pq;
vector<pii> arr[1001];
vector<pii> barr[1001];
int dist[1001];
int dist2[1001];

void dijkst(int src) {
	pq.push({ 0,src });

	fill(&dist[0], &dist[1001], 1000000);
	dist[src] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int with = pq.top().second;
		
		pq.pop();

		if (dist[with] >= cost) {

			for (int i = 0; i < arr[with].size(); i++) {
				int m = arr[with][i].first;
				int nextDist = cost + arr[with][i].second;

				if (dist[m] > nextDist) {
					dist[m] = nextDist;
					pq.push({ nextDist,m });
				}

			}
				

		}

	}
}

void dijkst2(int src) {
	pq.push({ 0,src });

	fill(&dist2[0], &dist2[1001], 1000000);
	dist2[src] = 0;
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int with = pq.top().second;

		pq.pop();

		if (dist2[with] >= cost) {

			for (int i = 0; i < barr[with].size(); i++) {
				int m = barr[with][i].first;
				int nextDist = cost + barr[with][i].second;

				if (dist2[m] > nextDist) {
					dist2[m] = nextDist;
					pq.push({ nextDist,m });
				}

			}


		}

	}
}

int main() {
	int N;
	cin >> N;

	int M;
	cin >> M;


	int src;
	cin >> src;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ b,c });
		barr[b].push_back({ a,c });
	}
	dijkst(src);
	dijkst2(src);
	int max = 0;
	for (int i = 1; i <= N; i++) {
		if (max <= dist[i]+dist2[i]) {
			max = dist[i]+dist2[i];
		}
	}
	cout << max;
}