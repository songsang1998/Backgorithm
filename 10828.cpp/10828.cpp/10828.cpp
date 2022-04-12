#include<iostream>

using namespace std;



int main() {
	int stack[10001];

	int top= 0;
	int N;
	cin >> N;

	string text;

	for (int i = 0; i < N; i++) {
		cin >> text;
		

		if (text == "top") {
			if (top == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << stack[top-1] << "\n";
			}
		}
		else if (text == "empty")
		{
			if (top == 0) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (text == "size") {
			cout << top << "\n";
		}
		else if (text == "pop") {
			if (top == 0) {
				cout << -1 << "\n";
			}
			else {
				cout << stack[top - 1] << "\n";
				top--;
			}
		}
		else {
			int r;
			cin >> r;

			stack[top] = r;
			top++;
		}
	}

}