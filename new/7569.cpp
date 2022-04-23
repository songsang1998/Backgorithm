#include<iostream>
#include<queue>
#define iii pair<int, pair<int, int>>
#define F first 
#define S second 
#define qiii <iii>
using namespace std;

queue qiii que;

int arr[102][102][102];
int visted[102][102][102];
int temp[2] = { -1,1 };
void Super_BFS() {

	while (!que.empty()) {
		iii tempque = que.front();
		que.pop();

		for (int i = 0; i < 2; i++) {
			if (arr[temp[i] + tempque.F][tempque.S.F][tempque.S.S] == 0) {
				if (visted[temp[i] + tempque.F][tempque.S.F][tempque.S.S] == 0) {
					visted[temp[i] + tempque.F][tempque.S.F][tempque.S.S] = visted[tempque.F][tempque.S.F][tempque.S.S] + 1;
					que.push(make_pair(temp[i] + tempque.F, make_pair(tempque.S.F, tempque.S.S)));
				}

			}

		}
		for (int i = 0; i < 2; i++) {

			if (arr[tempque.F][temp[i] + tempque.S.F][tempque.S.S] == 0) {
				if (visted[tempque.F][temp[i] + tempque.S.F][tempque.S.S] == 0) {
					visted[tempque.F][temp[i] + tempque.S.F][tempque.S.S] = visted[tempque.F][tempque.S.F][tempque.S.S] + 1;
					que.push(make_pair(tempque.F, make_pair(temp[i] + tempque.S.F, tempque.S.S)));
				}

			}
		}for (int i = 0; i < 2; i++) {

			if (arr[tempque.F][tempque.S.F][temp[i] + tempque.S.S] == 0) {
				if (visted[tempque.F][tempque.S.F][temp[i] + tempque.S.S] == 0) {
					visted[tempque.F][tempque.S.F][temp[i] + tempque.S.S] = visted[tempque.F][tempque.S.F][tempque.S.S] + 1;
					que.push(make_pair(tempque.F, make_pair(tempque.S.F, temp[i] + tempque.S.S)));
				}

			}
		}

	}


}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int I;
	int J;
	int K;
	cin >> I;
	cin >> J;
	cin >> K;


	fill(&arr[0][0][0], &arr[101][101][101], -1);


	for (int k = 1; k <= K; k++) {
		for (int j = 1; j <= J; j++) {
			for (int i = 1; i <= I; i++) {
				int a;
				cin >> a;
				arr[i][j][k] = a;
				if (a == 1) {
					que.push(make_pair(i, make_pair(j, k)));
					visted[i][j][k] = 1;
				}
				else if (a == -1) {
					visted[i][j][k] = 1;
				}

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
			for (int k = 1; k <= K; k++) {
				if (error) {
					break;
				}
				if (arr[i][j][k] == 0 || arr[i][j][k] == 1) {
					if (visted[i][j][k] != 0) {
						if (max < visted[i][j][k]) {
							max = visted[i][j][k];
						}
					}
					else {
						error = true;
						break;
					}
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