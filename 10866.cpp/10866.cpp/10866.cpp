#include<iostream>
#include<deque>
using namespace std;
int main() {

	deque<int> deques;

	int N;
	cin >> N;
	string text;
	for (int i = 0; i < N; i++) {
		cin >> text;

		if (text == "push_front") {
			int a;
			cin >> a;
			deques.push_front(a);
		}
		else if (text == "push_back") {
			int a;
			cin >> a;
			deques.push_back(a);
		}
		else if (text == "pop_front") {
			if (deques.empty() == true) {
				cout << -1 << "\n";
			}
			else {
				int c = deques.front();
				cout << c << "\n";
				deques.pop_front();
			}
		}
		else if (text == "pop_back") {
			if (deques.empty() == true) {
				cout << -1 << "\n";
			}
			else {
				int c = deques.back();
				cout << c << "\n";
				deques.pop_back();
			}
		}
		else if (text == "size") {
			cout << deques.size() << "\n";
		}
		else if (text == "empty") {
			if (deques.empty() == true) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (text == "front") {
			if (deques.empty() == true) {
				cout << -1 << "\n";
			}
			else {
				int c = deques.front();
				cout << c << "\n";
			}
		}
		else if (text == "back") {
			if (deques.empty() == true) {
				cout << -1 << "\n";
			}
			else {
				int c = deques.back();
				cout << c << "\n";
			}
		}
	}

}