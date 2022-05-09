#include<iostream>
#include<vector>

#define pii pair<int,int>
#define piii pair<int,pii>
const int INF = 10000000;

using namespace std;
vector<piii> v;
int visted[501];

bool Bell(int N) {
	visted[N] = 0;
	for (int i = 1; i <= N-1; i++) {
		for (int j = 0; j< v.size(); j++) {
			int First = v[j].first;
			int Second = v[j].second.first;
			int Cost = v[j].second.second;

			if (visted[First] != INF && visted[First] + Cost < visted[Second]) {
				visted[Second] = visted[First] + Cost;
			}
		}
	}

	for (int j = 0; j< v.size(); j++) {
		int First = v[j].first;
		int Second = v[j].second.first;
		int Cost = v[j].second.second;

		if ( visted[First] + Cost < visted[Second]) {
			return true;
		}
	}

	return false;
}
int main() {
	int T;
	cin >> T;
	
	for (int t = 0; t < T; t++) {
		fill(&visted[0], &visted[501], INF);
		v.clear();
		
		int N, M, W;
		cin >> N>> M>>W;
		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a;
			cin >> b;
			cin >> c;
			v.push_back({ a,make_pair(b, c) });
			v.push_back({ b,make_pair(a, c) });
		}
		
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a;
			cin >> b;
			cin >> c;
			v.push_back({ a,make_pair(b, -c) });
		}
		
		if (Bell(N)) {
			cout << "YES"<< "\n";
		}
		else {
			cout << "NO" << "\n";
		}
		
		
	}
	
}