#include<iostream>
#include<queue>
#define ii pair<int, int>
#define F first 
#define S second 
#define qii <ii>
using namespace std;

queue qii que;

int arr[1002][1002];
int visted[1002][1002];
int temp[2] = { -1,1 };
void Super_BFS() {

	while (!que.empty()) {
		ii tempque = que.front();
		que.pop();

		for (int i = 0; i < 2; i++) {
			if (arr[temp[i] + tempque.F][tempque.S] == 0) {
				if (visted[temp[i] + tempque.F][tempque.S] == 0) {
					visted[temp[i] + tempque.F][tempque.S] = visted[tempque.F][tempque.S]+ 1;
					que.push(make_pair(temp[i] + tempque.F,tempque.S));
				}

			}

		}
		for (int i = 0; i < 2; i++) {

			if (arr[tempque.F][temp[i] + tempque.S] == 0) {
				if (visted[tempque.F][temp[i] + tempque.S] == 0) {
					visted[tempque.F][temp[i] + tempque.S] = visted[tempque.F][tempque.S] + 1;
					que.push(make_pair(tempque.F,temp[i] + tempque.S));
				}

			}
		}

	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int I;
	int J;
	
	cin >> I;
	cin >> J;
	


	fill(&arr[0][0], &arr[1001][1001], -1);


	
		for (int j = 1; j <= J; j++) {
			for (int i = 1; i <= I; i++) {
				int a;
				cin >> a;
				arr[i][j] = a;
				if (a == 1) {
					que.push(make_pair(i, j));
					visted[i][j] = 1;
				}
				else if (a == -1) {
					visted[i][j] = 1;
				}

			}
		}
	



	Super_BFS();
	int max = 1;
	bool error = false;

	for (int i = 1; i <= I; i++) {
		if (error) {
			break;
		}
		for (int j = 1; j <= J; j++) {
			if (error) {
				break;
			}
			
				if (arr[i][j] == 0 || arr[i][j] == 1) {
					if (visted[i][j] != 0) {
						if (max < visted[i][j]) {
							max = visted[i][j];
						}
					}
					else {
						error = true;
						break;
					}
				}

			
		}
	}

	if (error) {
		cout << -1;
	}
	else {
		cout << max - 1;
	}
}