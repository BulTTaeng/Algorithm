#include <iostream>
#include <cstring>

using namespace std;

int dp[22][22];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  memset(dp, 0,sizeof(dp));

  dp[1][1] = 1;
  dp[2][1] = 1;
  dp[2][2] = 1;

  for(int i =3; i<=n;i++){
    for(int j =0; j<=i; j++){
      
      dp[i][j] = dp[i-1][j];

      if(j==i){
        dp[i][j] = 0;
        for(int k =1; k<=j; k++){
          dp[i][j] += dp[i-1][k];
        }
      }

      if(dp[i-3][j] != 0 && (i-3) % 2 == 1){
        dp[i][j] = 0;
      }

      if(dp[i-4][j] != 0&& (i-4) %2 == 0){
        dp[i][j] = 0;
      }
      
    }

  }

  int ans =0;

  for(int i =1; i<=n; i++){
    ans += dp[n][i];
  }

  cout <<ans;
  
  return 0;

}
