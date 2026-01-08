#include <iostream>
#include <cstring>

using namespace std;

int dp[100002];
int N;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    solve();

    cout << dp[N];
    
    return 0;
}

void solve(){
    memset(dp, 0, sizeof(dp));

    for (int i =1; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        if (i >= 2) dp[i] = min(dp[i-2] + 1, dp[i]);
        if (i >= 5) dp[i] = min(dp[i-5] + 1, dp[i]);
        if (i >= 7) dp[i] = min(dp[i-7] + 1, dp[i]);
    }
    
}
