#include<iostream>
#include<string>
#include<map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	int arr[31];
	map<string, int> clother;
	cin >> T;
	for (int t = 0; t < T; t++) {
		clother.clear();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string k;
			getline(cin, k, ' ');
			string o;
			cin >> o;
			if (clother.find(o) == clother.end()) {
				clother.insert({ o, 1 });
			}
			else {
				clother[o] = clother[o] + 1;
			}

		}

		int M = 0;
		for (auto iter = clother.begin(); iter != clother.end(); iter++) {
			arr[M] = iter->second;
			M++;
		}
		int sum = 1;

		for (int i = 0; i < M; i++) {
			sum *= (arr[i] + 1);
		}
		cout << sum - 1 << "\n";
	}

}