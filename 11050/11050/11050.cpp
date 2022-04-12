#include <iostream>


using namespace std;


int factorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * factorial(n - 1);
	}
}
int main() {
	int N;
	int K;
	cin >> N >> K;

	int b = N - K;
	
	int a = (factorial(N)) / (factorial(K) * factorial(b));
			
	cout  << a << "\n";
		
	

		
	
}
