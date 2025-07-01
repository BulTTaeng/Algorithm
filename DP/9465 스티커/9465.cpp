#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int T, N;
int inp[2][100002];
int dp[2][100002];
int ans;

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> N;
        
        memset(dp, 0, sizeof(dp));

        for (int i =0; i<2; i++) {
            for (int j =1; j<=N; j++) {
                cin >> inp[i][j];
            }
        }

        cout << solve() << "\n";
    }

    return 0;
}

int solve() {
   dp[0][1] = inp[0][1];
   dp[1][1] = inp[1][1];

   for(int i=2; i<=N; i++) {
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + inp[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + inp[1][i];
   }

   return max(dp[0][N], dp[1][N]);
}
