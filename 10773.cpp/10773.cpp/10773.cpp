#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> a;

	int K;
	
	cin >> K;

	for (int i = 0; i < K; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			a.pop();
		}
		else {
			a.push(t);
		}
		
	}
	int sum = 0;
	while (!a.empty()) {
		sum += a.top();
		a.pop();
	}

	cout << sum << "\n";
}