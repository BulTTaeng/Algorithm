#include <iostream>
#include <cstring>

using namespace std;

int N, ans = 0;
int inp[502][502];
int dp[502][502];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        for (int j = 1; j<=i; j++) {
            cin >> inp[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));

    solve();

    cout << ans;

    return 0;
}

void solve() {
    dp[1][1] = inp[1][1];
    
    for (int i =2; i<=N; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + inp[i][j];
        }
    }

    for (int i=1; i<=N; i++) {
        ans = max(ans, dp[N][i]);
    }
}
