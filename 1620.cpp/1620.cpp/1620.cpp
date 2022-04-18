#include<iostream>
#include<string>

#include<map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N;
	cin >> M;
	map <string, int > mapdog;
	map <int, string > dogmap;

	

	cin.ignore();

	for (int i = 0; i < N; i++) {
		string st;
		getline(cin, st);
		
		mapdog[st] = i+1;

		dogmap[i+1] = st;
	
	}

	

	for (int i = 0; i < M; i++) {
		
		
		string st;
	
		getline(cin, st);


		if (st[0] >='0' && st[0] <= '9' ) {
			int temp = stoi(st);
			
			cout << dogmap[temp]<<"\n";
		}
		else {
			cout << mapdog[st] <<"\n";
			
		}
		
	}
	
}