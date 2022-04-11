#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	string s;
	stack<char> x;
	char big[101];
	getline(cin,s);
	while (s != ".") {

	
 		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '(' || s[i] == '[')
			{
				x.push(s[i]);
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

		if (x.empty() == true && flag == true) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}
		
		while (!x.empty()) x.pop();
		getline(cin, s);
		
	}
}