#include <iostream>
#include <cstring>

using namespace std;

int inp[1002];
int dp[1002][32][3];
int T ,W;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> T >> W;

  for(int i =1; i<=T; i++){
    cin >> inp[i];
  }

  memset(dp, 0, sizeof(dp));

  if(inp[1] == 1){
    dp[1][0][1] = 1;
  }
  else{
    dp[1][1][2] =1;
  }

  int maxi = -1;

  for(int i =2; i<=T; i++){
    for(int j= 0; j<=W; j++){
      
      if(inp[i] == 1){
        if(j == 0){
          dp[i][j][1] = dp[i-1][j][1] + 1;
        }

        else{
          dp[i][j][1] = dp[i-1][j][1] + 1;
          dp[i][j][2] = dp[i-1][j][2];
          if(dp[i-1][j-1][2] != 0)
            dp[i][j][1] = max(dp[i][j][1] , dp[i-1][j-1][2]+1);
        }
        
      }

      else{
        if(j == 0){
          dp[i][j][2] = dp[i-1][j][2] + 1;
        }
        else{
          dp[i][j][2] = dp[i-1][j][2] +1;
          dp[i][j][1] = dp[i-1][j][1];
          if(dp[i-1][j-1][1] != 0)
            dp[i][j][2] = max(dp[i][j][2] , dp[i-1][j-1][1] + 1);
        }

      }

    }
  }
  
    for (int i = 0; i <= W; i++){
        maxi= max(maxi, max(dp[T][i][1], dp[T][i][2]));
    }
  cout << maxi;
  return 0;

}
