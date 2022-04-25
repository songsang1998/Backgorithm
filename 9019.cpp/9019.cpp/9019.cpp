#include<iostream>
#include<queue>

#include<algorithm>
using namespace std;


int X;
int Y;
queue <int> que;
string Visted[10001];


void BFS(int start, int end) {
	que.push(start);
	Visted[start] = "";
	while (!que.empty()) {
		int temp = que.front();
		que.pop();
		if (temp == end) {
			break;
		}
		int one = (temp * 2) % 10000;
		int two = temp-1;
		if (two == -1) {
			two = 9999;
		}
		
		int three= (temp/1000) +((temp%1000)*10) ;
		int four = (temp % 10)*1000 + (temp /10);
		
		
		if (Visted[one].size()== 0 && one !=start) {
			que.push(one);
			Visted[one] = Visted[temp] + "D";
		}
		if (Visted[two].size()== 0&& two != start) {
			que.push(two);
			Visted[two] = Visted[temp] + "S";
		}if (Visted[three].size() == 0 && three != start) {
			que.push(three);
			Visted[three] = Visted[temp] + "L";
		}if (Visted[four].size()==0 && four != start) {
			que.push(four);
			Visted[four] = Visted[temp] + "R";
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		while (!que.empty()) {
			que.pop();
		}
		for (int i = 0; i <= 10000;i++) {
			Visted[i] = "\0";
		}
		cin >> X;
		cin >> Y;
		BFS(X,Y);
		cout << Visted[Y] << "\n";
	}
}