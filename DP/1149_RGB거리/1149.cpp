#include <iostream>
#include <climits>

using namespace std;

int N;
int inp[1002][4];
int dp[1002][4];
int ans = INT_MAX;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        for (int j =1; j<=3; j++) {
            cin >> inp[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}

void solve() {
    dp[1][1] = inp[1][1];
    dp[1][2] = inp[1][2];
    dp[1][3] = inp[1][3];

    for (int i=2; i<=N; i++) {
        dp[i][1] = min(dp[i-1][2], dp[i-1][3]) + inp[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][3]) + inp[i][2];
        dp[i][3] = min(dp[i-1][1], dp[i-1][2]) + inp[i][3];
    }

    for (int i =1; i<=3; i++) {
        ans = min(ans, dp[N][i]);
    }
}
