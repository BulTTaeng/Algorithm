#include <iostream>
#include <cstring>

using namespace std;

int dp[22];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 7;

  for(int i =5; i<=n; i++){
    if (i%2 == 0){
      dp[i] = dp[i-1] * 2 - dp[i-4] -dp[i-5];
    }
    else{
      dp[i] = dp[i-1] *2;
    }
  }

  cout << dp[n];
  return 0;

}
