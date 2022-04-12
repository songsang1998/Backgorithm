#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> go;

	int N;
	cin >> N;

	string text;
	for (int i = 0; i < N; i++) {
		cin >> text;

		if (text == "push") {
			int q;
			cin >> q;
			go.push(q);
		}
		else if (text == "pop") {
			if (go.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << go.front() << "\n";
			
				go.pop();
			}
		}
		
		else if (text == "size") {
			cout << go.size() << "\n";
		}
		else if (text == "empty") {
			if (go.empty()) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (text == "front") {
			if (go.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << go.front() << "\n";

				
			}
		}
		else if (text == "back") {
			if (go.empty()) {
				cout << "-1" << "\n";
			}
			else {
				cout << go.back() << "\n";

				
			}
		}
	}
}