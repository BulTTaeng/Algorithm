#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int N;
int dp[5002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    if (dp[N] == INT_MAX) {
        cout << -1;
    } else {
        cout << dp[N];
    }
    
    return 0;
}

void solve() {
    dp[0] = INT_MAX;
    dp[1] = INT_MAX;
    dp[2] = INT_MAX;
    dp[3] = 1;
    dp[4] = INT_MAX;
    dp[5] = 1;
    for (int i =6; i<=N; i++) {
        dp[i] = INT_MAX;
        if (dp[i-5] != INT_MAX) {
            dp[i] = dp[i-5] + 1;
        }
        if (dp[i-3] != INT_MAX) {
            dp[i] = min(dp[i-3]+1, dp[i]);
        } 
    }
}
