#include <iostream>

using namespace std;

int N;
long long dp[4];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    solve();

    cout << dp[N%3];

    return 0;
}

void solve() {
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    for (int i =3; i<=N; i++) {
        int mod = i%3;
        dp[mod] = dp[(mod+1) % 3] + dp[(mod+2) % 3];
    }
}
