#include<iostream>
#include<memory.h>
#include<vector>
#include<cmath>
using namespace std;
#define INF 99999999
int timeArr[1001][1001];
pair<bool,pair<int, int>> cityLocation[1001];
int N, T;


void BasicSet(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				timeArr[i][j] = 0;
				continue;
			}
			int startcityx = cityLocation[i].second.first;
			int startcityy = cityLocation[i].second.second;
			int descityx = cityLocation[j].second.first;
			int descityy = cityLocation[j].second.second;
			bool startcityspecalx = cityLocation[i].first;
			bool startcityspecaly = cityLocation[j].first;
			int tempsize = abs(startcityx - descityx) + abs(startcityy - descityy);
			
			if (startcityspecalx && startcityspecaly) {
				if (T < tempsize) {
					tempsize = T;
				}
			}

			timeArr[i][j] = tempsize;
		}
	}
}

void floyd(int n) {


	BasicSet(n);


	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (timeArr[i][k] + timeArr[k][j] < timeArr[i][j]) {
					timeArr[i][j] = timeArr[i][k] + timeArr[k][j];
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		memset(timeArr[i], INF, sizeof(timeArr[0][0] * N * N));
	}
	for (int i = 1; i <= N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bool tempa = (a == 1) ? true : false;
		cityLocation[i] = make_pair(tempa, make_pair(b,c));
	}

	floyd(N);
	
	int M;
	cin >> M;

	for (int m = 1; m <= M; m++) {
		int a, b;
		cin >> a >> b;
		cout << timeArr[a][b] << '\n';
	}


}