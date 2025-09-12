#include <iostream>
#include <cstring>

using namespace std;

int N;
int inp[100002];
int dp[100002];
int ans = 0;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i=1; i<=N; i++) {
        cin >> inp[i];
    }

    memset(dp,0,sizeof(dp));
    
    solve();

    cout << ans;
    
    return 0;
}

void solve() {
    dp[1] = inp[1];
    ans = inp[1];

    for (int i=2; i<=N; i++) {
        dp[i] = max(inp[i], dp[i-1] + inp[i]);
        ans = max(ans, dp[i]);
    }
}
