#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
long long inp[100002];
long long dp[100002][2];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    for (int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    solve();

    cout << min(dp[N][0] , dp[N][1]);
    
    return 0;
}

void solve() {
    memset(dp, 0 , sizeof(dp));

    dp[1][1] = inp[1];

    for (int i =2; i<=N; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = min(dp[i-1][1], dp[i-1][0]) + inp[i];
    }
}
