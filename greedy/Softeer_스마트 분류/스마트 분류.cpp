#include<iostream>
#include <cstring>

using namespace std;

char line[20012];

int N,K;
int ans = 0;

void solve(){

	bool grap = false;

	for(int i =0 ;i<N; i++){

		if(line[i] == 'P'){
			for(int j = i-K; j < i ; j++){
				if(j<0) continue;

				if(line[j] == 'H'){
					line[j] = 'Q';
					ans++;
					grap = true;
					break;
				}
			}

			if(grap) {
				grap = false;
				continue;
			}

			for(int j =i+1; j<=i+K ; j++){
				if(line[j] == 'H'){
					line[j] = 'Q';
					ans++;
					break;
				}
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	for(int i =0; i<N; i++){
		cin >> line[i];
	}

	solve();
	cout << ans;
	
	return 0;
}
