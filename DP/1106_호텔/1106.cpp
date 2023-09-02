#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[22][1002];

int cost[21];
int cus[21];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int c , n;

  cin >> c >> n;

  for(int i =0; i<n; i++){
    cin >> cost[i] >> cus[i];
    dp[i][cus[i]] = cost[i]; 
  }

  int i =1, j = 1;
  int temp;

  for(int i =1; i<=c; i++){
    temp = j * cus[0];
    if(i <= temp){
      dp[0][i] = cost[0] * j;
    }
    else{
      j++;
      dp[0][i] = cost[0] * j;
    }
  }

  for(int i =1; i<n; i++){
    for(int j  =1; j<=c; j++){
      if(j < cus[i]) dp[i][j] = min(dp[i-1][j] , cost[i]);
      else{
        dp[i][j] = min(dp[i-1][j-cus[i]] + cost[i], dp[i-1][j]);
        dp[i][j] = min(dp[i][j] , dp[i][j-cus[i]] + cost[i] );
      } 
    }
  }

  cout << dp[n-1][c];
  return 0;
}
