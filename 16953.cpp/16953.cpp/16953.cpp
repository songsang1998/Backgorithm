#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;


long long A, B;
bool check = false;
void BFS(int start) {
	queue<pair<long long,int>> q;

	q.push(make_pair(start,1));
	while (!q.empty()) {
		

		long long k = q.front().first;
		int depth = q.front().second;
		q.pop();
		if (k == B) {
			check = true;
			cout << depth;
			break;
		}
		if (k * 10+1 <= B) {
			q.push(make_pair(k * 10 + 1,depth+1));
		}
		if (k * 2 <= B) {
			q.push(make_pair(2*k,depth+1));
		}
	}

}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	check = false;
	cin >> A >> B;

	BFS(A);

	if (!check) {
		cout << -1;
	}

}