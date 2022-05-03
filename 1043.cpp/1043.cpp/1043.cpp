#include<iostream>
#include<vector>
using namespace std;

vector<int> truehuman;
int arr[51];
vector<int> v[51];
int Find(int x) {
	if (arr[x] == x) return x;
	return x = Find(arr[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	arr[x] = y;
}



int main() {
	
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int N;

	int M;
	
	cin >> N;

	cin >> M;

	int L;
	cin >> L;

	for (int i = 1; i <=N; i++) {
		arr[i] = i;
	}

	for (int l = 0; l < L; l++) {
		int temp;
		cin >> temp;
		truehuman.push_back(temp);

	}

	for (int i = 0; i < M; i++) {
		int M2;
		cin >> M2;
		int onejo;
		for (int j = 0; j < M2; j++) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
			if (j == 0) {
				onejo = temp;
			}
			else {
				Union(onejo, temp);
				onejo = temp;
			}
			
		}
	}


	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool flag = true;
		for (int j = 0; j < v[i].size(); j++) {
			int x = v[i][j];
			if (flag == false) {
				break;
			}
			for (int k = 0; k < truehuman.size(); k++) {
				if (Find(x) == Find(truehuman[k])) {
					flag = false;
					break;
				}
			}
		}

		if (flag == true) {
			ans++;
		}
	}

	cout << ans;
}