#include <iostream>

using namespace std;

int N, K;
int dp[1002];

#define MOD 10007

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j >= 1; j--) {
            dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }

    cout << dp[K];
  
    return 0;
}
