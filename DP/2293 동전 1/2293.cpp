#include<iostream>
#include<cstring>

using namespace std;

int N, K;
int coins[102];
int dp[10002];
int ans = 0;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for(int i =0; i<N; i++) {
        cin >> coins[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;

    solve();

    cout << dp[K];

    return 0;
}

void solve() {
    for(int i=0; i<N; i++) {
        int coin = coins[i];
        for (int j=coin; j<=K; j++) {
            dp[j] += dp[j-coin];
        }
    }
}
