#include<iostream>
#include<queue>
using namespace std;
#define pii pair<int,int>

int visted[22][22];

int arr[22][22];
bool gameend;
int fishsize;
int nam = 0;
int xarr[4] = { -1, 1, 0, 0 };
int yarr[4] = { 0,0,-1, 1 };
pii maxpair;
pii minpair;
int amin;
pii BFS(pii kpair) {
	fill(&visted[0][0], &visted[21][21], 0);
	
	queue<pii> qqueue;
	qqueue.push(kpair);
	
	int min = 999999;
	pii tempmaxpair = { 25,25};
	while (!qqueue.empty()) {
		pii s = qqueue.front();
		qqueue.pop();
		
		for (int i = 0; i < 4; i++) {
			if (visted[s.first + xarr[i]][s.second+yarr[i]]==0) {
					if (fishsize >= arr[s.first + xarr[i]][s.second + yarr[i]]) {
						qqueue.push({ s.first + xarr[i],s.second + yarr[i] });
						visted[s.first + xarr[i]][s.second + yarr[i]] = visted[s.first][s.second] + 1;
						if (min > visted[s.first + xarr[i]][s.second + yarr[i]]) {
							if (arr[s.first + xarr[i]][s.second + yarr[i]]!= 0 && arr[s.first + xarr[i]][s.second + yarr[i]]<fishsize) {
								min = visted[s.first + xarr[i]][s.second + yarr[i]];
								tempmaxpair = { s.first + xarr[i],s.second + yarr[i] };
							}
						}
						else if (min == visted[s.first + xarr[i]][s.second + yarr[i]]) {
							if (s.first + xarr[i] < tempmaxpair.first) {
								if (arr[s.first + xarr[i]][s.second + yarr[i]] != 0 && arr[s.first + xarr[i]][s.second + yarr[i]] < fishsize) {
									min = visted[s.first + xarr[i]][s.second + yarr[i]];
									tempmaxpair = { s.first + xarr[i],s.second + yarr[i] };
								}
							}
							else if (s.first + xarr[i] == tempmaxpair.first) {
								if (s.second + yarr[i] < tempmaxpair.second) {
									if (arr[s.first + xarr[i]][s.second + yarr[i]] != 0 && arr[s.first + xarr[i]][s.second + yarr[i]] < fishsize) {
										min = visted[s.first + xarr[i]][s.second + yarr[i]];
										tempmaxpair = { s.first + xarr[i],s.second + yarr[i] };
									}
								}
							}
						}
					}
			}
		}

	}
	arr[kpair.first][kpair.second] = 0;
	if (tempmaxpair.first == 25) {
		return kpair;
	}
	else {
		amin = min;
		return tempmaxpair;

	}
	

}


int main() {
	int N;
	cin >> N;
	pii kpair;
	fishsize = 2;
	nam = 0;
	gameend = false;
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= N+1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == N + 1) {
				arr[i][j] = 200;
			}
			else {
				int num;
				cin >> num;
				arr[i][j] = num;
				if (num == 9) {
					kpair = { i,j };
				}
			}
			
		}

	}
	maxpair = kpair;
	int nums = 0;
	while (!gameend) {
		
		minpair =BFS(maxpair);
		arr[minpair.first][minpair.second] = 9;
		nam++;
		
		if (minpair.first == maxpair.first && minpair.second==maxpair.second) {
			gameend = true;
		}
		else {
			maxpair = minpair;
		}
		if (fishsize < 7) {
			if (fishsize == nam) {
				fishsize++;
				nam = 0;
			}
		}
		if (!gameend) {
			nums += amin;
		}
	}

	cout << nums;
}