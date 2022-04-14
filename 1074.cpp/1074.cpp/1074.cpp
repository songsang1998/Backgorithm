#include<iostream>
#include<cmath>
using namespace std;


long long sum = 0;
long long r;
long long c;
bool clear;
void Zf(int n,long long io,long long jo) {
	if (io == r) {
		if (jo == c) {
			clear = true;
		}
	}
	if (clear == true) {
		return;
	}


	if (n > 1) {
			
				
			
				int b = n - 1;
				long long ibig;
				long long nbig;
				ibig =  (pow(2, b));
				nbig = (pow(ibig, 2));
				

				if (io+ibig  <= r) {
					if (jo+ibig  <= c) {
						Zf(b, io+ibig, jo+ ibig);
						sum += (nbig * 3);
					}
					else {
						Zf(b, io+ibig, jo);
						sum += (nbig*2);
					}
				}
				else {
					if (jo+ibig  <= c) {
						Zf(b, io, jo+ ibig);
						sum += nbig;
					}
					else {
						Zf(b, io, jo);
						sum += 0;
					}

				}

				

				
				
			
		
	}
	else if(n == 1) {

		if ((long long)io+1 <= r) {
			if ((long long)jo + 1 <= c) {
				sum += 3;
			}
			else {
				sum += 2;
			}
		}
		else {
			if ((long long)jo + 1 <= c) {
				sum += 1;
			}
			else {
				sum += 0;
			}

		}
	}
	
	return;
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	

	cin >> N >> r >> c;
	clear == false;
	Zf(N,0,0);
	cout << sum;
}