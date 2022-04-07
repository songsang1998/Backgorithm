#include<iostream>

using namespace std;

int main() 
{
	int N, M;
	cin >> N;
	cin >> M;

	int memory[10001];
	int max=0;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (max < x) {
			max = x;
		}
		memory[i] = x;
		
	}
		
	long long maxs = max;
	long long mins = 1;
	int answer = 0;
	while (mins<= maxs) {
		
	
		long long mid = ((mins + maxs) / 2);
	
		int sum = 0;
		
		for (int i = 0; i < N; i++) {
			sum += memory[i] / mid;
		}
			
		if (sum >= M) {
			mins = mid + 1;
			
			answer = mid;
			
		}
		else {
			maxs = mid-1;
		}
		
	}
	cout << answer;
	
	
	
}