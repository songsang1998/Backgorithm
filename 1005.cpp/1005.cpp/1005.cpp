#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;
int indegree[1001];

vector<int> vec[1001];

int dev[1001];
int bulldingTimeTable[1001];
int T;
int N, M;
int W;


void bulding(int finalW) {
	
	queue<pair<int, int>>q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push({ i,bulldingTimeTable[i] });
			dev[i] = bulldingTimeTable[i];
		}
	}


	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;

		if (cur == W) {
			printf("%d\n", dev[cur]);
			return;
		}

		q.pop();
		
		
			for (int i = 0; i < vec[cur].size(); i++) {
				int next =vec[cur][i];

				int next_cost = time + bulldingTimeTable[next];

				if (next_cost > dev[next])
				{
					dev[next] = next_cost;
				}

				indegree[next] -= 1;

				if (indegree[next] == 0) {
					q.push({ next,dev[next] });
				}
			}
		
			
	}

}

int main() {


	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N,&M);
	
		
		for (int i = 0; i < 1001; i++) {
			vec[i].clear();
		
			indegree[i] = 0;
			bulldingTimeTable[i] = 0;
			dev[i] = 0;
		}
		for (int n = 1; n <= N; n++) {	
			int temp;
		
			scanf("%d", &temp);
			bulldingTimeTable[n] = temp;
		}
		for (int m = 0; m < M; m++) {
			int a,b;
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			indegree[b]++;
	
		}
		
		
		scanf("%d", &W);
		bulding(W);
		
		
	}

}