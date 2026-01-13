#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int dp[10002];

#define MOD 1000000007

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M; 

    solve();

    cout << dp[N];
    
    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i =2; i<=N; i++) {
        dp[i] = dp[i-1];
        if (i >= M) dp[i] = (dp[i] + dp[i-M]) % MOD;
    }
}
