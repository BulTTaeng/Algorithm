#include <iostream>
#include <cstring>

using namespace std;

int N;
int A[1002];
int ans = 1;

int dp[1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    memset(dp, 0, sizeof(dp));

    solve();

    cout << ans;

    return 0;
}

void solve() {
    for (int i=0; i<N; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            if (A[j] > A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }
}
