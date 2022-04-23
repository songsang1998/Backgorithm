#include<iostream>
#include<queue>
#define pii pair<int,int>
using namespace std;




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	bool arr[1000001];

	for (int t = 0; t < T; t++) {
		fill(arr, arr + 1000001, false);
		priority_queue<pii, vector<pii>, less<pii>> pqueue;
		priority_queue<pii, vector<pii>, greater<pii>> tqueue;
		int K;
		cin >> K;

		for (int k = 0; k < K; k++) {
			char s;
			cin >> s;
			int temp;
			cin >> temp;

			if (s == 'I') {
				pqueue.push(make_pair(temp, k));
				tqueue.push(make_pair(temp, k));

				arr[k] = true;

			}
			else if (s == 'D') {

				if (temp == 1) {

					while (!pqueue.empty() && arr[pqueue.top().second] == false) {

						pqueue.pop();


					}
					if (!pqueue.empty()) {
						int x = pqueue.top().second;
						pqueue.pop();

						arr[x] = false;
					}
				}
				else if (temp == -1) {
					while (!tqueue.empty() && arr[tqueue.top().second] == false) {

						tqueue.pop();

					}
					if (!tqueue.empty()) {
						int x = tqueue.top().second;
						tqueue.pop();

						arr[x] = false;
					}

				}
			}



		}



		while (!pqueue.empty() && arr[pqueue.top().second] == false) {
			pqueue.pop();

		}

		while (!tqueue.empty() && arr[tqueue.top().second] == false) {
			tqueue.pop();
		}

		if (!pqueue.empty() && !tqueue.empty()) {
			int x = pqueue.top().first;
			cout << x << " ";
			int y = tqueue.top().first;
			cout << y << "\n";
		}
		else {
			cout << "EMPTY" << "\n";
		}



	}
}