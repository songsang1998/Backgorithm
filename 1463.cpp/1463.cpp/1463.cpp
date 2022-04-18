#include<iostream>
#include<algorithm>
using namespace std;



int arr[1000001];
void sum(int x) {
	
	int a= 1000000;
	int b= 1000000;
	
	if (x % 2 == 0) {
		 a= arr[x / 2] + 1;
	}
	if (x % 3 == 0) {
		 b = arr[x / 3] + 1;
	}
	
	int c = arr[x - 1] + 1;

	arr[x]=min(min(a, b), c);
	
	
	return;

}


int main() {
	int N;
	cin >> N;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	
	 
	for (int i = 4; i <= N; i++) {
		
		
		sum(i);
		
		
		
		
	}
	

	cout << arr[N];
}