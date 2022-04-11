#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int N;
	string s;
	stack<char> x;
	char big[101];
	
	cin >> N;
	cin.ignore();
	for (int n = 0; n < N; n++) {
		getline(cin, s);
	
		bool super = false;
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[')
			{
				x.push(s[i]);
				super = true;
			}
			else if (s[i] == ')') {
				if (x.empty() == false) {
					char q = x.top();
					x.pop();
					if (q != '(') {

						flag = false;
						break;
					}
				}
				else {


					flag = false;
					break;
				}
			}
			else if (s[i] == ']') {
				if (x.empty() == false) {
					char q = x.top();
					x.pop();

					if (q != '[') {

						flag = false;
						break;
					}

				}
				else {
					flag = false;
					break;
				}
			}
		}


			if (x.empty() == true && flag == true && super == true) { 
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}

			while (!x.empty()) x.pop();
		
		
	}
}