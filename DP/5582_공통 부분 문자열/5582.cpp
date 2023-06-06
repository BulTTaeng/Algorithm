#include <iostream>

using namespace std;

int dp[4002][4002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string str1 ,str2;

  cin>> str1 >> str2;

  int ans = 0;

  for(int i =0; i<=str1.size(); i++){
    
    for(int j =0; j<=str2.size() ; j++){
      if( j == 0 || i == 0){
        dp[i][j] = 0;
      }

      else{
        if(str1[i-1] == str2[j-1]){
          dp[i][j] = dp[i-1][j-1] + 1;

          if(ans < dp[i][j]){
            ans = dp[i][j];
          }
        }
        else{
          dp[i][j] = 0;
        }
      }
      
    }

  }

  cout << ans;
  return 0;
}
