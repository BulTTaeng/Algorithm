#include <iostream>

using namespace std;

int T, N;

void solve();
int ans = 0;
int dp[12];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    solve();

    while(T--) {
        cin >> N;

        cout << dp[N] << "\n";
    }
    
    return 0;
}

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i =4; i<=11; i++) {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
}
