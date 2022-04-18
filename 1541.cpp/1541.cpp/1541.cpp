#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;

	getline(cin, s);

	string q;
	int sum = 0;
	char opp;
	opp = 'x';
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			if (opp == '-') {
				sum -= stoi(q);
				q.clear();
			}
			else {
				sum += stoi(q);
				q.clear();
			}
		}
		else if (s[i] == '-') {
			if (opp == 'x') {
				opp = '-';
				sum += stoi(q);
				q.clear();
			}
			else {
				sum -= stoi(q);
				q.clear();
			}
		}
		else {
			q.push_back(s[i]);
		}
	}
	if (opp == '-') {
		sum -=stoi(q);
	}
	else {
		sum += stoi(q);
	}

	cout << sum;
}