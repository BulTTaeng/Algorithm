#include <iostream>
#include <cstring>

using namespace std;

int input[17][17];
int dp[18][18];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N, M , K;

  cin >> N >> M >> K;

  memset(dp, 0, sizeof(dp));
  dp[1][1] = 1;

  for(int i =1; i<=N; i++){
    
    for(int j =1; j<=M; j++){
      
      dp[i+1][j] = dp[i+1][j] + dp[i][j];
      dp[i][j+1] = dp[i][j+1]  + dp[i][j];
      
    }

  }

  int row ,col;

  if(K == 0){
    cout << dp[N][M];
    return 0;
  }

  if(K % M == 0){
    row = K/M;
    col = M;
  }
  else{
    row = K/M + 1;
    col = K % M;
  }

  int ans;
  ans = dp[row][col] * dp[N-row+1][M-col+1];
  cout << ans;
  return 0;
  

}
