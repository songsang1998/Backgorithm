#include<iostream>
#include<algorithm>
using namespace std;


int arr[200002];

int main() {

	int N;
	int M;
	cin >> N;
	cin >> M;





	for (int i = 200000; i >= 0; i--) {
		int sum = 0;
		if (i > M) {
			arr[i] = i - M;
		}
		else if (i == M) {
			arr[i] = 0;
		}
		else
		{
			int temp1 = M - i;
			int temp2 = 9999999;
			int temp3 = 9999999;

			if (i < 200000) {
				temp3 = arr[i + 1] + 1;
			}

			if (i <= 100000 && i != 0) {
				temp2 = arr[i * 2] + 1;
			}

			if (i < 200000) {
				int q = min(min(temp1, temp2), temp3);
				arr[i] = q;
				
				

				if (q + 1 < arr[i + 1]) {
					arr[i + 1] = q + 1;
				}


				
			}



		}



	}

	for (int i = 0; i <= 100000; i++) {
		
		

		if (arr[i + 1] > arr[i] + 1) {
			arr[i + 1] = arr[i] + 1;
		}

	}
	cout << arr[N];

}