#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int,vector<int>,less<int>> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;

		if (k == 0) {
			if (q.empty()) {
				cout << 0 << "\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(k);
		}
	}
}
