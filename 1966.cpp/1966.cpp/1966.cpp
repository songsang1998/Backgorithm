#include <iostream>
using namespace std;



int main() {

	int T;
	int N;
	int Arr[101];
	cin >> T;

	int x;
	int sum = 0;

	for (int k = 0; k < T; k++) {
		sum = 0;
		cin >> N;
		cin >> x;

		for (int i = 0; i < 101; i++) {

			Arr[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			int v;
			cin >> v;
			Arr[i] = v;
		}

		int num;

		num=Arr[x];
		int t = 0;
		for (int j = 9; j >= num; j--) {
			int q = t;
			int i = q;

			do {
				
				if (num != j) {
					if (Arr[i] == j) {
						sum++;
						t = i;
					}
				}
				else {
					
					if (Arr[i] == num) {

						sum++;
						if (x == i) {
							break;
						}

					}
				}
				i++;
				if (i == N) {
					i = 0;
				}
			} while (i != q);

		}
		
		cout << sum << endl;
		
	}

	
	
}
