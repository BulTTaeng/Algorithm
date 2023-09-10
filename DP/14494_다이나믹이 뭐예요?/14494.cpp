#include <iostream>
#include <cstring>

using namespace std;

int dp[1002][1002];

#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , m;

  cin >> n >> m;

  memset(dp, 0, sizeof(dp));

  dp[1][1] = 1;

  for(int i =1; i<=n; i++){
    for(int j =1; j<=m; j++){
      dp[i+1][j] = (dp[i][j] + dp[i+1][j]) % MOD;
      dp[i+1][j+1] = (dp[i][j] + dp[i+1][j+1]) % MOD;
      dp[i][j+1] = (dp[i][j] + dp[i][j+1]) % MOD;
    }
  }

  cout << dp[n][m];
  return 0;
} 
