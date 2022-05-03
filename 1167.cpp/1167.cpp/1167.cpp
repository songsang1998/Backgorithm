#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<pair<int,int>> arr[100001];
stack<int> istack;
int visted[100001];
bool check[100001];
int DFS(int ii) {
	fill(&visted[0], &visted[100001], 0);
	fill(&check[0], &check[100001], false);
	check[ii] = true;
	istack.push(ii);
	int max = 0;
	int number = 1;
	while (!istack.empty()) {
		int q = istack.top();
		istack.pop();
		
		for (int i = 0; i < arr[q].size(); i++) {
			int k = arr[q][i].first;
			if (check[k] == false) {
				check[k] = true;
				istack.push(k);
				visted[k] = visted[q]+ arr[q][i].second;
				if (visted[k] > max) {
					max = visted[k];
					number = k;
				}
			}
	


			

		}
				
	}

	return number;
}
int main() {
	int V;
	cin >> V;

	for (int v = 0; v < V; v++) {
		int t;
		cin >> t;
		int q;
		cin >> q;
		while (q != -1) {
			int o;
			cin >> o;
			arr[t].push_back({ q,o });
			cin >> q;
		}
	}


	int temp=	DFS(1);
	int temp2 = DFS(temp);
	cout<< visted[temp2];
}