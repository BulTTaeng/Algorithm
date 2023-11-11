#include <iostream>
#include <algorithm>

using namespace std;

int input[27][5];
int dp[27];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for(int i =1; i<=N; i++){
    for(int j = 1; j<=3; j++){
      cin >> input[i][j];
    }
  }
  dp[0] = 0;
  dp[1] = input[1][3];

  for(int i =2; i<=N; i++){
    dp[i] = max(dp[i-1] , dp[i-2] + input[i][3]); 
  }

  cout << dp[N];
  return 0;


}
