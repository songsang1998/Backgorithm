#include<iostream>
#include <string>
using namespace std;

int main() {

	int T;
	cin >> T;

	while (T != 0) {
		
		string s = to_string(T);
		if (s.length() % 2 == 0) {
			bool OK = true;
			for (int i = 0; i < s.length()/2; i++) {
				if (s[i] == s[s.length() - 1 -i]) {

				}
				else {
					OK = false;
					cout << "no" << endl;
					break;
				}
			}
			if (OK) {
				cout << "yes" << endl;
			}
		}
		else {
			bool OK = true;
			for (int i = 0; i < s.length() / 2; i++) {
				if (s[i] == s[s.length() - 1 -i]) {

				}
				else {
					OK = false;
					cout << "no"<< endl;
					break;
				}
			}
			if (OK) {
				cout << "yes"<< endl;
			}
		}


	cin >> T;

	}

}