#include<iostream>
#include<queue>
#include<vector>
#define INF 3000001

#define pii pair<int,int>

using namespace std;

vector<pii> arr[20001];
int visted[20001];
priority_queue<pii,vector<pii>,greater<pii>> piiq;

void disktra(int src) {
	fill(&visted[0], &visted[20001], INF);
	piiq.push({0, src});
	visted[src] = 0;
	while (!piiq.empty()) {
		pii a = piiq.top();
		piiq.pop();
		int count = a.first;
		int with = a.second;
		if (visted[with] >= count) {
			for (int i = 0; i<arr[with].size(); i++) {
				int nextcount = count + arr[with][i].second;
				int m = arr[with][i].first;
				if (visted[m] > nextcount) {
					visted[m] = nextcount;
					piiq.push({ nextcount,m });
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N,M,src;
	cin >> N>>M>> src;
	for (int m = 0; m < M; m++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		arr[a].push_back({ b, c });
		
	}
	disktra(src);
	for(int i=1; i<=N;i++){
		if (visted[i] < INF) {
			cout << visted[i] << "\n";
		}
		else {
			cout << "INF" << "\n";
		}
	}
}