#include<iostream>
#include<cstring>

using namespace std;

int N;
int dp[1000002];

#define MOD 15746

void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[N];
    return 0;
}

void solve() {
    dp[1] = 1;
    dp[2] = 2;

    for(int i =3; i<=N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
}
