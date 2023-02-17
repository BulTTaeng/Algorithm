#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

int N , M,  K;
int dp[3001][3001];
int n[3001];
int m[3001];
int ans = 0;

void lcs(){

	memset(dp , 0 , sizeof(dp));

	for(int i =1; i<=N; i++){
		for(int j = 1; j<=M; j++){
			if(n[i] == m[j]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else{
				dp[i][j] = 0;
			}
			ans = max(ans , dp[i][j]);
		}
	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M >> K;
	int temp;

	for(int i =1; i<=N; i++){
		cin >> n[i];
	}

	for(int j =1; j<=M; j++){
		cin >> m[j];
	}

	lcs();
	cout << ans;
	
	return 0;
}
