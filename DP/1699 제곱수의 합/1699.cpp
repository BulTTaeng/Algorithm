#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int dp[100002];
int ans = 0;
int N;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[N];

    return 0;
}

void solve() {
    int root = floor(sqrt(N));
    int tempN = N;

    dp[0] = 0;

    for (int i=1; i<=N; i++) {
        int curr = floor(sqrt(i));
        dp[i] = 987654321;
        for (int j=1; j<=curr; j++) {
            dp[i] = min(dp[i], dp[i-(j*j)] + 1);
        }
    }
}
