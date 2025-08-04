#include<iostream>
#include<cstring>

using namespace std;

int T, N, M;

long long dp[32][32];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    solve();

    while(T--){
        cin >> N >> M;
        cout << dp[N][M] << "\n";
    }

    return 0;
}

void solve() {

    memset(dp, 0, sizeof(dp));
    
    for (int i =0; i<=29; i++) dp[0][i] = 1;

    for (int i=1; i<=29; i++) {
        for (int j=i; j<=29; j++) {
            if (i == j) dp[i][j] = 1;
            else {
                for (int k = j; k>0; k--){
                    dp[i][j] += dp[i-1][k-1];
                }
            }
        }
    }
}
