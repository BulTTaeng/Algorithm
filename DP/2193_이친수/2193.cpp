#include <iostream>
#include <cstring>

using namespace std;

int N;
long long dp[2][92];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[0][N] + dp[1][N];

    return 0;
}

void solve() {
    dp[0][1] = 0;
    dp[1][1] = 1;

    dp[0][2] = 1;
    dp[1][2] = 0;

    for (int i =3; i<=N; i++) {
        dp[0][i] = dp[0][i-1] + dp[1][i-1];
        dp[1][i] = dp[0][i-1];
    }
}

/* 
피보나치 풀이
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long a = 0, b = 1; // F(0)=0, F(1)=1
    for (int i = 2; i <= N; i++) {
        long long c = a + b;
        a = b;
        b = c;
    }

    cout << b << "\n";
    return 0;
}

*/
