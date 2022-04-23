#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> KMPTable(string R) {
	int size = R.length();
	vector<int> KMPTable(size, 0);

	for (int i = 1, j = 0; i < size; i++) {
		while (j > 0 && R[i] != R[j]) {
			j = KMPTable[j - 1];
		}
		if (R[i] == R[j]) {
			KMPTable[i] = ++j;
		}


	}

	return KMPTable;
}

vector<int> KMP(string qtext, string ktext) {
	int qm = qtext.length();
	int km = ktext.length();

	vector<int> pos;
	vector<int> pi = KMPTable(qtext);

	for (int i = 0, j = 0; i < km; i++) {
		while (j > 0 && ktext[i] != qtext[j]) {
			j = pi[j - 1];
		}
		if (ktext[i] == qtext[j]) {
			if (j == qm - 1) {
				pos.push_back(i - qm + 1);
				j = pi[j];
			}
			else j++;
		}
	}
	return pos;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	int M;
	cin >> M;

	string R;
	string k;
	cin >> k;
	int sum = 0;


	R = "I";

	for (int i = 0; i < N; i++) {
		R += "OI";
	}

	vector<int> v = KMP(R, k);


	cout << v.size();
}