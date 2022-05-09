#include<iostream>
#include<stack>
using namespace std;

stack<char> st;


int main() {
	string k;
	cin >> k;

	for (int i = 0; i < k.size(); i++) {
		if (k[i] == '+' || k[i]=='-') {
			if (st.size()> 0) {
				if (st.top() == '*' || st.top() == '/') {
					while (st.size() > 0 && st.top() != '(') {
						char a = st.top();
						st.pop();
						cout << a;
					}
				}
				else if (st.top()== '+' || st.top() == '-') {
					char a = st.top();
					st.pop();
					cout << a;
				}
			}
			st.push(k[i]);
		}
		else if (k[i]=='*'||k[i]=='/') {
			if (st.size() > 0) {
				if (st.top() == '*' || st.top() == '/') {
					char a = st.top();
					st.pop();
					cout << a;
				}
			}
			st.push(k[i]);
			

		}else if (k[i]=='(') {
			st.push(k[i]);
		}
		else if (k[i]==')') {
			while (st.top() != '(') {
				char a = st.top();
				st.pop();
				cout << a;
			}

			st.pop();
		}
		else {
			cout << k[i];
		}
		
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}