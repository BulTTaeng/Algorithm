#include <iostream>
#include <cstring>

using namespace std;

int inp[22];

int dp[22][22][22];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , op1 , op2, cls;

  cin >> n;
  cin >> op1 >> op2;
  cin >> cls;

  for(int i =1; i<=cls; i++){
    cin >> inp[i];
  }

  memset(dp, -1 , sizeof(dp));
  dp[op1][op2][0] = 0;

  for(int i =1 ; i<=cls ; i++){
    for(int j = 1; j<=20; j++){
      for(int k = 1 ; k<=20; k++){
        if(dp[j][k][i-1] != -1){
          
          if(dp[inp[i]][k][i] == -1){
            dp[inp[i]][k][i]  = dp[j][k][i-1] + abs(j-inp[i]);  
          }
          else{
            dp[inp[i]][k][i]  = min(dp[inp[i]][k][i], dp[j][k][i-1] + abs(j-inp[i]));
          }

          if(dp[j][inp[i]][i] == -1){
            dp[j][inp[i]][i] = dp[j][k][i-1] + abs(k-inp[i]) ;
          }
          else {
            dp[j][inp[i]][i] = min (dp[j][inp[i]][i] ,dp[j][k][i-1] + abs(k-inp[i])) ;
          }
          

          //cout << dp[inp[i]][k][i] << " " << dp[j][inp[i]][i] << " ";
        }
      }
    }
    //cout << "\n";
  }

  int mi =999999999;

  for(int i=1; i<=20; i++){
    for(int j =1; j<=20 ; j++){
      if(mi > dp[i][j][cls] && dp[i][j][cls] != -1){
        mi = dp[i][j][cls];
      }
    }
  }

  cout << mi;
  return 0;
}
