#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>
using namespace std;

bool visted[101];
vector<int> vector_list[101];
queue<int> bqueue;
int num = 0;
void BFS(int n) {
	
	visted[n] = true;
	bqueue.push(n);
	
	while (!bqueue.empty()) {
		int x = bqueue.front();
		bqueue.pop();
		
		for (int i = 0; i < vector_list[x].size(); i++) {
			int ax = vector_list[x][i];

			if (visted[ax] == false) {
				visted[ax] = true;
				bqueue.push(ax);
				num++;
			}
			
		}
	}

	return;
	

}


int main() {

	memset(visted, 0, sizeof(visted));
	
	
	int N;
	cin >> N;
	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int a;
		int b;
		cin >> a;
		cin >> b;
		vector_list[a].push_back(b);
		vector_list[b].push_back(a);
	}
	BFS(1);
	cout << num;
}