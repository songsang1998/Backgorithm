#include<iostream>
#include<queue>
using namespace std;

int arr[52][52];
bool check[52][52];
int sum = 0;

void dfs(int N, int M) {
	check[N][M] = false;

	for (int i = -1; i <= 1; i++) {
		if (arr[N + i][M] == 1 && check[N + i][M] == true) {
			dfs(N + i, M);

		}
		
		
	}
	for (int j = -1; j <= 1; j++) {
		if (arr[N][M + j] == 1 && check[N][M + j] == true) {

			dfs(N , M+j);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int n, m, o;
		n = 0;
		m = 0;

		cin >> n;
		cin >> m;
		cin >> o;
		
		sum = 0;
		

		for (int i = 0; i <= 51; i++) {
			for (int j = 0; j <= 51; j++) {

				check[i][j] = false;
				arr[i][j] = 0;
			}
		}

		for (int i = 0; i < o; i++) {
			int r, q;
			cin >> r;
			cin >> q;
			arr[r+1][q+1] = 1;
			check[r+1][q+1] = true;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (check[i][j] == true) {
					sum++;
					dfs(i, j);
					
				}
			}
		}

		cout << sum<<endl;
	}
}


