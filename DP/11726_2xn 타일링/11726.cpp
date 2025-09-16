#include <iostream>

using namespace std;

#define MOD 10007;

int N;
int dp[1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    solve();

    cout << dp[N];
    
    return 0;
}

void solve() {
    dp[1] = 1;
    dp[2] = 2; // dp[1] 하나추가 / 1
    dp[3] = 3;
    for (int i=4; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD ;
    }
}
