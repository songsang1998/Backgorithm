#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N;
	int M;
	int B;

	cin >> N;
	cin >> M;
	cin >> B;

	vector<vector<int>> v;
	int time;
	int bigtime=999999999;
	int hight=0;
	int block;
	bool flag = true;
	for (int i = 0; i < N; i++) {
		vector<int> q;
		for (int j = 0; j < M;j++) {
			
			int a;
			cin >> a;
			q.push_back(a);
		}
		v.push_back(q);
	}

	for (int k = 0; k <= 256; k++) {
		time = 0;
		block = B;
		flag = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				
				 if(v[i][j] <k) {
					int Pblock = k - v[i][j];
					block -= Pblock;
					time += Pblock;

				}else if (v[i][j] > k) {
					time += (v[i][j] - k) * 2;
					block += (v[i][j] - k);
				}
			}
			

		}
		
	

		if (block < 0) {
			flag = false;
		}

		if (flag == true) {
			if (bigtime >=time) {
				bigtime = time;
				hight = k;
			}
			
		}

		
	}
	cout << bigtime << " " << hight;
	
}