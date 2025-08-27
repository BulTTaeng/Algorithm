#include <iostream>
#include <cstring>

using namespace std;

int N;
int T[21];
int P[21];
int dp[21];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(T, 0, sizeof(T));
    memset(P, 0, sizeof(P));

    for (int i =0; i<N; i++) {
        cin >> T[i] >> P[i];
    }

    solve();

    cout << dp[N];

    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    
    for (int i=0; i<N; i++) {
        int t = T[i];
        int p = P[i];

        dp[i+1] = max(dp[i+1], dp[i]);

        if ((t+ i) <= N) {
            dp[i+t] = max(dp[i+t], dp[i] + p);
        }
    }
}
