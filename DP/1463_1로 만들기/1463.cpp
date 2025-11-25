#include <iostream>
#include <climits>

using namespace std;

int N;
int dp[1000002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[1] = 0;
    for (int i =2; i<=N; i++) {
        dp[i] = INT_MAX;
    }

    solve();

    cout << dp[N];
    
    return 0;
}

void solve() {
    
    for (int i =1; i<=N; i++) {
        if (i*3 <= N) dp[i*3] = min (dp[i*3], dp[i] + 1);
        if (i*2 <=N) dp[i*2] = min(dp[i*2], dp[i] + 1);
        dp[i+1] = min(dp[i+1], dp[i] + 1);
    }
}
