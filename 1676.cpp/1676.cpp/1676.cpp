#include<iostream>
using namespace std;





int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int N;
	cin >> N;
	int sum = 0;

	for (int i = 1; i <= N; i++) {
		
		if (i % 125 == 0) {
			sum += 3;
		}
		else if (i % 25 == 0) {
			sum += 2;
		}
		else if (i % 5 == 0) {
			sum++;
		}
	}
	
	cout << sum;
}