#include<iostream>
#include<queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	pii pairArray[100001];

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a;
		cin >> b;
		pairArray[i].F = b;
		pairArray[i].S = a;
		pq.push(pairArray[i]);

	}
	int start = 0;
	int sum = 0;
	while (!pq.empty()) {
		pii A = pq.top();
		pq.pop();
		if (A.S >= start) {
			sum++;
			start = A.F;
		}
	}

	cout << sum;
}