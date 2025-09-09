#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[10][102];
int ans = 0;

void solve();

#define MOD 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << ans;

    return 0;
}

void solve() {
    dp[0][1] = 0;
    for (int i=1; i<=9; i++) {
        dp[i][1] = 1;
    }

    for (int i=2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            if (j == 0) {
                dp[j][i] = dp[1][i-1];
            } else if (j == 9) {
                dp[j][i] = dp[8][i-1];
            } else {
                dp[j][i] = (dp[j-1][i-1] + dp[j+1][i-1]) % MOD;
            }
        }
    }

    for (int i=0; i<=9; i++) {
        ans = (ans + dp[i][N]) % MOD;
    }
}
