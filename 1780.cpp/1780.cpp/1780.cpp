#include<iostream>
#include<math.h>
using namespace std;

int Num[2188][2188];

int onesum;
int zerosum;
int monesum;

void Nine(int N,int x,int y) {
	
	bool one = true;
	bool two = true;
	bool three = true;
	
	for (int i = x; i <= x+N-1; i++) {
		if (one || two || three) {
			for (int j = y; j <= y + N - 1; j++) {
				if (one || two || three) {
					if (Num[i][j] == 0) {
						one = false;
						two = false;
					}
					else if (Num[i][j] == 1) {
						two = false;
						three = false;
					}
					else {
						one = false;
						three = false;
					}
				}
				else {
					break;
				}


			}
		}
		else {
			break;
		}

	}

	if (one) {
		onesum += 1;
		return;
	}else if(two) {
		monesum += 1;
		return;
	}
	else if (three) {
		zerosum += 1;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Nine(N / 3, x+(N/3*i), y + (N/3 * j));
			}
			
		}
		
		return;
	}
}

int main() {
	int N; 
	cin >> N;
	
	onesum = 0;
	zerosum = 0;
	monesum = 0;


	int A = N;
	int sum = 0;
	/*while (A != 1) {
		A = A / 3;
		sum++;
	}*/

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int q;
			cin >> q;
			Num[i][j]=q;
		}
	}
	Nine(N,1,1);

	cout << monesum << '\n';
	cout << zerosum << '\n';
	cout << onesum << '\n';
}