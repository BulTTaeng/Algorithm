#include <iostream>
#include <cstring>

using namespace std;

int dp[52];
int N;

#define MOD 1000000007;

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
    
    dp[0] = 1;
    dp[1] = 1;

    for (int i =2; i<=N; i++) {
        dp[i] = (1 + dp[i-1] + dp[i-2]) % MOD;
    }
}
