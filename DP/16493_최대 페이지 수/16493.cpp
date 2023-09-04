#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[22][202];

int input[22][2];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N ,M;

  cin >> N  >> M;

  for( int i =1; i<=M; i++){
    for(int j=0; j<2; j++){
      cin >> input[i][j];
    }
  }

  memset(dp,0,sizeof(dp));

  for(int i =input[1][0]; i<=N; i++){
    dp[1][i] = input[1][1];
  }

  for(int i =2; i<=M; i++){
    for(int j =1 ; j<=N; j++){
      dp[i][j] = dp[i-1][j];
      if (input[i][0] <= j){
        dp[i][j] = max(dp[i][j] , dp[i-1][j-input[i][0]] + input[i][1]);
      }
      
    }
  }

  cout << dp[M][N];
  return 0;
}
