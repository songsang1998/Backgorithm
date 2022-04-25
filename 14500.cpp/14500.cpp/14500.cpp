#include <iostream>
using namespace std;
int arr[511][511];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N;

	cin >> M;
	int ar[2];
	pair<int, int> br[8][4] = { {{0,0}, {1,0}, {2,0},{2,1}},{{0,0}, {0,1}, {-1,1},{-2,1}}
	,{{0,0}, {0,1}, {1,1},{2,1}},{{0,0}, {1,0}, {1,1},{1,2}},
	{{0,0}, {0,1}, {0,2},{1,0}},{{0,0}, {0,1}, {1,0},{2,0}},
	{{0,0}, {0,1}, {0,2},{-1,2}},{{0,0}, {0,1}, {0,2},{1,2}} };
	pair<int, int> dr[4][4] = { {{0,0}, {1,0}, {1,1},{2,1}},{{0,0}, {1,0}, {1,-1},{2,-1}},{{0,0}, {0,1}, {1,1},{1,2}},{{0,0}, {0,-1}, {1,-1},{1,-2}} };
	pair<int, int> er[4][4] = { {{0,0}, {1,0}, {1,1},{2,0}},{{0,0}, {1,0}, {1,-1},{2,0}},{{0,0}, {0,1}, {1,1},{0,2}},{{0,0}, {0,1}, {-1,1},{0,2}} };
	for (int i = 4; i <= N+3; i++) {
		for (int j = 4; j <= M+3; j++) {
			int k;
			cin >> k;
			arr[i][j] = k;
		}
	}
	int maxs = 0;
	for (int i = 4; i <= N+3; i++) {
		for (int j = 4; j <= M+3; j++) {
			ar[0] = 0;
			ar[1] = 0;
			for (int q = 0; q <= 3; q++) {
				ar[0] += arr[i][j + q];
			}
			for (int q = 0; q <= 3; q++) {
				ar[1] += arr[i+q][j];
			}
			int a = max(ar[0], ar[1]);
			
			int b =0;
		
			for (int q= 0; q < 8; q++) {
				b = max(b, arr[i+br[q][0].first][j+ br[q][0].second] + arr[i + br[q][1].first][j+ br[q][1].second] + arr[i +br[q][2].first][j+ br[q][2].second]  + arr[i + br[q][3].first][j + br[q][3].second]);
			}

			int c = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];

			int d = 0;
			for (int q = 0; q < 4; q++) {
				d= max(d, arr[i + dr[q][0].first][j + dr[q][0].second] + arr[i + dr[q][1].first][j + dr[q][1].second] + arr[i + dr[q][2].first][j + dr[q][2].second]  + arr[i + dr[q][3].first][j + dr[q][3].second]);
			}

			int e = 0;
			for (int q = 0; q < 4; q++) {
				e = max(e, arr[i + er[q][0].first][j + er[q][0].second] + arr[i + er[q][1].first][j + er[q][1].second] + arr[i + er[q][2].first][j + er[q][2].second] + arr[i + er[q][3].first][j + er[q][3].second]);
			}

			maxs = max(max(max(max(max(a, b),c),d),e),maxs);
		}
	}

	cout << maxs;
}