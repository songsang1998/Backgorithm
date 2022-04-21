#include<iostream>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
int arr[27][27];
bool visted[27][27];
using namespace std;

int Danarr[626];
int ba[2] = { -1,1 };
int DFS(int x, int y) {
	queue<pii> q;
	pii pai;
	pai.first = x;
	pai.second = y;
	q.push(pai);
	int sum = 0;
	while (!q.empty()) {
		sum++;
		
		pii tempp = q.front();
		
		q.pop();
		int tx = tempp.first;
		int ty = tempp.second;

		for (int i = 0; i < 2; i++) {
			if (arr[tx + ba[i]][ty] == 1) {
				if (visted[tx + ba[i]][ty] == false) {
					pii tempp2;
					visted[tx + ba[i]][ty] = true;
					tempp2.first = tx + ba[i];
					tempp2.second = ty;
					q.push(tempp2);
				}
			}
		}
		for (int i = 0; i < 2; i++) {
			if (arr[tx][ty + ba[i]] == 1) {
				if (visted[tx][ty + ba[i]] == false) {
					pii tempp2;
					visted[tx][ty + ba[i]] = true;
					tempp2.first = tx;
					tempp2.second = ty + ba[i];
					q.push(tempp2);
				}
			}
		}

	}
	return sum;

}

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			cin >> a;
			arr[i][j] = a-'0';
		}
	}
	int num = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1) {
				if (visted[i][j] == false) {
					num++;
					visted[i][j] =true;
					Danarr[num]=DFS(i, j);
					
				}
			}
			
			
		}
	}
	cout << num << "\n";
	sort(Danarr+1, Danarr + num+1);
	for (int i = 1; i <= num; i++) {
		cout << Danarr[i] << "\n";
	}

}