#include<iostream>
#include<map>
using namespace std;

map<string, string> maps;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < N; i++) {
		string a;
		string b;
		cin >> a;
		cin >> b;
		maps[a] = b;
	}
	for (int i = 0; i < M; i++) {
		string a;
		cin >> a;
		cout << maps[a] << "\n";
	}
}