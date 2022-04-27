#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int arr[50001];

int main(){
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		double k;
		k = sqrt(i);
		int mins;
		
		if (k - int(k) == 0) {
			arr[i] = 1;
			
		}
		else {
			mins = arr[i - 1];
			for (int j = 1; j*j <i; j++) {
				mins = min(mins, arr[i-j*j]);
			}
			arr[i] = mins+1;
		}
	}

	cout << arr[N];
}