#include<iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int number=1;
	bool end = false;
	int check[1000001];
	bool checksum[1000001];
	for(int i = 0; i < N; i++) {
		int A = 0;
		cin >> A;
		check[i] = A;
		checksum[i] = false;
	}

	for (int i = 0; i < N; i++) {
		if (number <= check[i]) {
			checksum[check[i]] = true;
			number = check[i];
		}
		else {

			if (checksum[check[i] + 1] == true) {
				checksum[check[i]] = true;
			}
			else {
				cout << "NO";
				end = true;
				break;
			}
		}
	}

	if (end == true) {
		return 0;
	}
	
		number = 1;
	for (int i = 0; i < N; i++) {
		if (number < check[i]) {
			for (int j = number; j < check[i]; j++) {
				cout << "+" << '\n';
				number += 1;
			}
		}
		if (number == check[i]) {
				cout << "+" << '\n';
				cout << "-" << '\n';
				number += 1;
			}
		else {
				cout << "-" << '\n';
			}

	}
	

}