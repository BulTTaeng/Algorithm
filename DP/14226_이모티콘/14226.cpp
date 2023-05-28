#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int dp[1002][1002];
vector<int> clip[1002];
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n;
  
  memset(dp, -1 , sizeof(dp));

  dp[2][1] = 2;
  dp[3][1] = 3;
  dp[3][2] = 5;

  int temp;

  for(int i = 4; i<=n; i++){
    dp[i][1] = i;
  
    for(int j = 2; j<i; j++){
      
      for(int k = 1; k<j; k++){
        if(dp[j][k] == -1) continue;
        
        else{
          if(j + k >=i){
            temp = dp[j][k] + (j + k - i ) + 1;
            if(dp[i][k] == -1)
              dp[i][k] =temp;
            else
              dp[i][k] = min(temp, dp[i][k]);
          }

          if(j + j >= i ){
            temp = dp[j][k] + (j*2 -i) + 2;
            if(dp[i][j] == -1) dp[i][j] = temp;
            else
              dp[i][j] = min(dp[i][j] , temp);
          }
        }

      }

    }

  }

  int ans = 999999999;

  for(int i =1; i<=n ;i++){
    //cout << dp[n][i] << " ";
    if(dp[n][i] == -1) continue;
    else ans = min(ans, dp[n][i]);
  }

  //cout <<"\n";

  cout << ans;
  return 0;
}
