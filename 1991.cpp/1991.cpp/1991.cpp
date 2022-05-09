#include<iostream>
#include<vector>
using namespace std;

#define pcc pair<char,char>
pcc p[27];


void Treecenter(char c) {
	int x = c - 'A' + 1;
	pcc ptemp = p[x];
	cout << c;
	if (ptemp.first != '.') {
		Treecenter(ptemp.first);
	}
	if (ptemp.second != '.') {
		Treecenter(ptemp.second);
	}

}

void TreeLeft(char c) {
	int x = c - 'A' + 1;
	pcc ptemp = p[x];
	if (ptemp.first != '.') {
		TreeLeft(ptemp.first);
	}
	cout << c;
	if (ptemp.second != '.') {
		TreeLeft(ptemp.second);
	}

}

void TreeLight(char c) {
	int x = c - 'A' + 1;
	pcc ptemp = p[x];
	if (ptemp.first != '.') {
		TreeLight(ptemp.first);
	}
	if (ptemp.second != '.') {
		TreeLight(ptemp.second);
	}
	cout << c;
}
int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N; n++) {
		char a, b, c;
		cin >> a;
		cin >> b;
		cin >> c;
		p[a-'A'+1] = { b,c };

	}

	Treecenter('A');
	cout <<'\n';
	TreeLeft('A');
	cout << '\n';
	TreeLight('A');
}