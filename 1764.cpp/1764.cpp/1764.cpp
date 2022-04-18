#include<iostream>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	map <string, int> notListen;
	vector <string> notListenSee;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		string q;
		cin >> q;
		notListen[q] = 1;

	}

	for (int i = 0; i < M; i++) {
		string q;
		cin >> q;
		if (notListen[q] == 1) {
			notListenSee.push_back(q);
		}

	}

	sort(notListenSee.begin(), notListenSee.end());
	cout << notListenSee.size() << "\n";
	for (int i = 0; i < notListenSee.size(); i++) {
		cout << notListenSee[i] << "\n";
	}

}