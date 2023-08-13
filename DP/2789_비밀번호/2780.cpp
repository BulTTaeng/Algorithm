#include <iostream>

using namespace std;

int dp[12][1002];

#define MOD 1234567

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T;

  cin >> T;

  for(int i =0; i<=9; i++){
    dp[i][1] = 1;
  }

  for(int i =2; i<=1000; i++){
    dp[0][i] = (dp[7][i-1]) % MOD;
    dp[1][i] = (dp[2][i-1] + dp[4][i-1]) % MOD;
    dp[2][i] = (dp[1][i-1] + dp[3][i-1] + dp[5][i-1]) % MOD;
    dp[3][i] = (dp[2][i-1] + dp[6][i-1]) % MOD;
    dp[4][i] = (dp[1][i-1] + dp[5][i-1] + dp[7][i-1]) % MOD;
    dp[5][i] = (dp[2][i-1] + dp[4][i-1] + dp[6][i-1]+ dp[8][i-1]) % MOD;
    dp[6][i] = (dp[3][i-1] + dp[5][i-1] + dp[9][i-1]) % MOD;
    dp[7][i] = (dp[0][i-1] + dp[4][i-1] + dp[8][i-1]) % MOD;
    dp[8][i] = (dp[5][i-1] + dp[7][i-1] + dp[9][i-1]) % MOD;
    dp[9][i] = (dp[6][i-1] + dp[8][i-1]) % MOD;

  }

  int inp;
  int ans = 0;

  for(int i = 0; i<T; i++ ){
    cin >> inp;
    for(int j =0; j<=9; j++){
      ans += dp[j][inp];
    }
    ans = ans % MOD;
    cout << ans <<endl;
    ans = 0;
  }
  
  return 0;
}
