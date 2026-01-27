#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int N, H;

long long dp[32];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> N;

    solve();

    cout << dp[abs(H-N)];
    
    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    for (int i = 1; i<=abs(H-N); i++) {
        for (int j =1; j<=i; j++) {
            dp[i] += (dp[j-1] * dp[i-j]);
        } 
    }
}
// 0 : 1
// 1 : 1
// 2 : 1 + 1 = 2
// 3 : 2 + 2 + 1 = 5
// 4 : 5*1 + 2*2 + 1*5  = 14
