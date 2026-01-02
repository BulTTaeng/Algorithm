#include <iostream>
#include <cstring>

using namespace std;

int N;
int M;

long long dp[33][33];

void pascal();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    memset(dp, 0, sizeof(dp));
    pascal();
    
    cout << dp[M-1][N-1];
    
    return 0;
}

void pascal() {
    dp[0][0] = 1;
	for (int i = 1; i <= M; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
	}
}
