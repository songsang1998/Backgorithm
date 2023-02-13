#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> vec[200001];

int degree[200001];
int N;

vector<int> yes;
void TSort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0 || degree[i]==1) {

			q.push(i);
			degree[i] = -1;
		}
	}
	
	while (!q.empty()) {
		int start = q.front();
		
		q.pop();
		for (int i = 0; i < vec[start].size(); i++) {
			int next = vec[start][i];
			degree[next]--;

			if (degree[next] == 0 || degree[next] == 1) {
				q.push(next);
				degree[next] = -1;
			}
		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cout.tie(0);



	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;

		vec[i].push_back(a);
		degree[a]++;
		vec[i].push_back(b);
		degree[b]++;
	}
	TSort();

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 2) {
			yes.push_back(i);
		}

	}
	if (yes.size() > 0) {
		cout << yes.size() << "\n";
		for (int i = 0; i < yes.size(); i++) {

			if (i > 0) {
				cout << " ";
			}
			cout << yes[i];

		}
	}
	else {
		cout << 0;
	}
}