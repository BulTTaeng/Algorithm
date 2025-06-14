#include <iostream>
#include <cstring>

using namespace std;

int N, ans = 0;
int A[1002];
int dp[1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =0; i<N; i++) {
        cin >> A[i];
    }

    solve();

    cout << ans;

    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    int temp = 0;
    for (int i=0; i<N; i++) {
        temp = A[i];
        for (int j=0; j<i; j++) {
            if (A[j] < A[i]) {
                temp = max (temp , A[i] + dp[j]);
            }
        }
        dp[i] = temp;
        ans = max(ans, dp[i]);
    }
}
