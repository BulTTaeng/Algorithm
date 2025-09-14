#include <iostream>
#include <cstring>

using namespace std;

int N;
int inp[302];
int dp[302];

int ans = 0;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(inp, 0, sizeof(inp));

    for (int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    memset(dp, 0 , sizeof(dp));

    solve();

    cout << dp[N];
    
    return 0;
}

void solve() {
    dp[0] = 0;
    dp[1] = inp[1];
    dp[2] = inp[1] + inp[2];
    
    for (int i = 3; i<=N; i++) {
        dp[i] = max(dp[i-3] + inp[i-1], dp[i-2]) + inp[i];
    }
}
