#include<iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> q;

	int N;
	cin >> N;
	int K;
	for (int i = 0; i < N; i++) {
		q.push(i + 1);
	}
	cin >> K;
	int r = 0;
	cout << "<";
	while (!q.empty()) {
		r++;
		if (r == K) {
			int k = q.front();
			
			if (q.size() == 1) {
				cout << k << ">";
			}
			else {
				cout << k << ", ";
			}
			q.pop();
			r = 0;
		}
		else {
			int k = q.front();
			q.pop();
			q.push(k);
		}
	}
}