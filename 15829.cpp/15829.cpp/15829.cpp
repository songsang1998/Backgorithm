#include<iostream>
using namespace std;


long long sqrx(char i, long long a) {
	if (a == 0) {
		return ((long long)i-96) % 1234567891;
	}else if(a == 1) {
		return ((long long)(i-96)*31) % 1234567891;
	}
	else {
		return 31 * sqrx(i, a - 1) % 1234567891;
	}
}



int main() {
	int L;
	cin >> L;
	char arr[100];

	for (int i = 0; i < L; i++) {
		char s;
		cin >> s;
		arr[i] = s;
	}
	long long sum = 0;
	for (int i = 0; i < L; i++) {
		sum+=sqrx(arr[i], i);
	}
	cout << sum%1234567891;
}

