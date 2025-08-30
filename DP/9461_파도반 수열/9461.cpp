#include <iostream>
#include <cstring>

using namespace std;

int T;
int N;
long long dp[102];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    solve();

    while(T--) {
        cin >> N;
        cout << dp[N] << "\n";
    }

    return 0;
}

void solve() {
    for(int i=6; i<=100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
}
