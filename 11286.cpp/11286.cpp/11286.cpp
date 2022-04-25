#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define pib pair<int,bool>
priority_queue<pib, vector<pib>, greater<pib>> q; 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		bool a = true;
		if (k > 0) {
			a = true;
		}
		else {
			a = false;
		}

		if (k == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
			}
			else {
				int r = q.top().first;
				if (q.top().second == false) {
					r = -r;
				}
				cout << r<< "\n";
				q.pop();
			}
		}
		else {
			if (a == false) {
				k = -k;
			}
			q.push(make_pair(k,a));
		}
	}
}
