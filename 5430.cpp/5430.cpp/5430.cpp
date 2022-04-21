#include<iostream>
#include<deque>
#include<string>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		bool Bawords = false; ;
		string s;
		deque <int> d;
		cin >> s;
		int num;
		cin >> num;
		char del;	
		cin >> del;
		
		bool error = false;
		for (int i = 0; i < num; i++) {
			int x;
			cin >> x;
			d.push_back(x);
			if (i != num - 1) {
				cin >> del;
			}
		}
		cin >> del;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'R') {
				Bawords = !Bawords;
			}
			else if(s[i] == 'D') {
				if (Bawords) {
					if (d.empty()) {
						error = true;
						break;
					}
					else {
						d.pop_back();
					}
				}
				else {
					if (d.empty()) {
						error = true;
						break;
					}
					else {
						d.pop_front();
					}
				}
			}
		}

		if (error == true) {
			cout << "error" << "\n";
		}
		else {
			cout << "[";
			while (!d.empty()) {
				int temp;
				if (Bawords) {
					temp = d.back();
					d.pop_back();
				}
				else {
					temp = d.front();
					d.pop_front();
				}
				cout << temp;
				if (d.empty()) {
					
				}
				else {
					cout << ",";
				}
			}

			cout << "]" << "\n";
		}
		
	}
}