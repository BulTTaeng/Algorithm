#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int N, M;
int dp[1002][1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=N; i++) {
        for(int j=1 ; j<=M; j++) {
            cin >> dp[i][j];    
        }
    }

    solve();

    cout <<dp[N][M];

    return 0;
}

void solve() {
    for(int i=1; i<=N; i++) {
        for(int j=1 ; j<=M; j++) {
            dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + dp[i][j];
        }
    }
}
