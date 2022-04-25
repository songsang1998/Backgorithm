#include<iostream>
using namespace std;

int arr[10];

int main() {
	int N;
	cin >> N;
	int Money;
	cin >> Money;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	int num = N - 1;
	int sum = 0;
	while (Money > 0) {
		if (Money >= arr[num]) {
			Money -= arr[num];
			sum++;
		}
		else {
			num--;
		}
	}
	cout << sum;
}