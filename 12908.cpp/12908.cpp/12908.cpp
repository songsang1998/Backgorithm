#include<iostream>
#include<memory.h>
#include<cmath>
#include<vector>
using namespace std;

#define INF 0x3f
vector <pair<int,int>> v;
int minvalue;
long long dist[8][8];
void Teleport() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (i != j) {
				int temp = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
				if (dist[i][j] > temp) {
					dist[i][j] = temp;
				}
				if (dist[j][i] > temp) {
					dist[j][i] = temp;
				}
			}
		}
	}

	for (int k = 0; k<v.size(); k++) {
		for (int i = 0; i<v.size(); i++) {
			for (int j = 0; j < v.size(); j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int xs, ys;
	int xe, ye;
	cin >> xs >> ys;
	cin >> xe >> ye;
	memset(dist, INF, sizeof(dist));
	v.push_back(make_pair(xs, ys));
	v.push_back(make_pair(xe, ye));
	for (int i = 0; i < 3; i++) {
		int x1, y1, x2, y2;
		cin >> x1>>y1>>x2>>y2;
		int number = v.size();
		v.push_back(make_pair(x1, y1));
		int number2 = v.size();
		v.push_back(make_pair(x2, y2));
		
		dist[number][number2] = 10;
		dist[number2][number] = 10;
	}

	Teleport();

	cout << dist[0][1];
	


	


}