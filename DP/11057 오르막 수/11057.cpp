#include<iostream>
#include<cstring>

using namespace std;

#define MOD 10007

int N;

int dp[2][11];
int ans = 0;

int solve();
int getSum(int n, int curr);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    cout << solve();

    return 0;
}

int solve() {
    for (int i=0; i<=9; i++) {
        dp[1][i] = 1;
    }
    for (int i= 2; i<=N; i++) {
        for (int j=0; j<=9; j++) {
            dp[i%2][j] = getSum((i+1) % 2, j);
        }
    }

    return getSum(N%2, 9);
}

int getSum(int n, int curr) {
    int temp = 0;
    for (int i=0; i<=curr; i++) {
        temp += dp[n][i];
        temp = temp % MOD;
    }
    return temp;
}
