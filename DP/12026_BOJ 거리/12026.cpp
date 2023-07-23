#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char input[1002];
int dp[1002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i =1; i<=n ; i++){
    cin >> input[i];
  }

  memset(dp, -1, sizeof(dp));

  dp[1] = 0;

  for(int i =1; i<=n; i++){
    for(int j = i+1; j<=n; j++){
      if(dp[i] == -1) continue;

      if(input[i] == 'B'){
        if(input[j] == 'O'){
          if(dp[j] == -1){
            dp[j] = dp[i] + (i-j) * (i-j);
          }
          else{
            dp[j] = min(dp[j] , dp[i] + (i-j) * (i-j) );
          }
          
        }
      }

      else if(input[i] == 'O'){
        if(input[j] == 'J'){
          if(dp[j] == -1){
            dp[j] = dp[i] + (i-j) * (i-j);
          }
          else{
            dp[j] = min(dp[j] , dp[i] + (i-j) * (i-j) );
          }
          
        }
      }

      else if(input[i] == 'J'){
        if(input[j] == 'B'){
          if(dp[j] == -1){
            dp[j] = dp[i] + (i-j) * (i-j);
          }
          else{
            dp[j] = min(dp[j] , dp[i] + (i-j) * (i-j) );
          }
          
        }
      }


    }
  }

  cout <<dp[n];
  return 0;
}
