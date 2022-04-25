#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	bool arr[21];
	fill(arr, arr + 21, false);
	for (int n = 0; n < N; n++) {
		string f;
		cin >> f;
		
		
		if (f == "add") {
			int a;
			cin >> a;
			
			arr[a] = true;
		}
		else if (f == "remove") {
			int a;
			cin >> a;
			
			arr[a] = false;
		}
		else if (f == "check") {
			int a;
			cin >> a;

			if (arr[a]) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (f == "toggle") {
			int a;
			cin >> a;

			arr[a] = !arr[a];
		}
		else if (f == "all") {
			fill(arr, arr + 21, true);
		}
		else if (f == "empty") {
			fill(arr, arr + 21, false);
		}
	}
}