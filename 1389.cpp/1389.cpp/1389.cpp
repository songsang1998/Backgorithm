#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

vector<int> list[101];
bool temp[101];
int quired[101];
queue<int> queueint;
int N, M;
int BFS(int v) {
	
	int sum = 0;
	
	
	temp[v] = true;
	queueint.push(v);
	
	while (!queueint.empty()) {
		

		int x = queueint.front();
	
		queueint.pop();
		for (int i = 0; i < list[x].size(); i++) {
			int k = list[x][i];
			if (temp[k] == false) {
				quired[k] = quired[x] + 1;
				queueint.push(k);
				temp[k] = true;
				
			}

		}
		
		
		
	}
	
	for (int i = 0; i <= N; i++) {
		sum += quired[i];
	}
	
	return sum;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	
	cin >> N >> M;
	int min = 999999999;
	int savenumber = 0;
	for (int i = 1; i <= M; i++) {
		
		int A, B;
		cin >> A >> B;

		list[A].push_back(B);
		list[B].push_back(A);

	}

	
	for (int i = 1; i <= N; i++) {
		memset(temp, false, sizeof(bool)*101);
		memset(quired, 0, sizeof(int) * 101);
		int q=BFS(i);
		if (min > q) {
			min = q;
			savenumber = i;
		}
	}

	cout << savenumber;
}