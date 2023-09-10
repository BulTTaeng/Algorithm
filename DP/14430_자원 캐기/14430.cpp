#include <iostream>
#include <algorithm>

using namespace std;

int dp[301][301];
int input[301][301];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N , M;

  cin >> N >> M;

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      cin >> input[i][j];
    }
  }

  for(int i =0; i<N; i++){
    
    for(int j =0; j<M ;j++){
      if(i == 0 && j==0) dp[i][j] = input[0][0];
      else if(i == 0){
        dp[i][j] = dp[i][j-1] + input[i][j];
      }
      else if (j==0){
        dp[i][j] = dp[i-1][j] + input[i][j];
      }
      else{
        dp[i][j] = max(dp[i-1][j] + input[i][j] , dp[i][j-1] + input[i][j]);
      }
    }
  }

  cout <<dp[N-1][M-1];
  return 0;
}
