#include <iostream>
#include <cstring>

using namespace std;

int N;
int inp[10002];
int dp[10002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for(int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[N];

    return 0;
}

void solve() {
    dp[1] = inp[1];
    dp[2] = inp[1] + inp[2];

    for (int i =3; i<=N; i++) {
        dp[i] = max(dp[i-2] + inp[i], dp[i-1]);
        dp[i] = max(dp[i], dp[i-3] + inp[i-1] + inp[i]);
    }
}
