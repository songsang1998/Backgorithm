#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;




int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;
	cin >> N;
	int a;

	priority_queue <int,vector<int>,greater<int>> Dog;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (a==0) {
			if (Dog.empty()==false) {
				
				int r = Dog.top();
				Dog.pop();
				cout << r << "\n";
				
				
			}
			else {
				cout << "0" << "\n";
			}
		}
		else {
			Dog.push(a);
		}
	}
}