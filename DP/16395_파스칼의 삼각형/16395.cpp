#include <iostream>

using namespace std;

long long dp[32][32];

int main() {
  int n, k;
  cin>>n >> k;

  dp[0][0] = 1;

  for(int i =1; i<=n; i++){
    for(int j =0; j<=i; j++){
      if (j == i || j==0){
        dp[i][j] = 1;
      }
      else{
        dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
      }
    }
  }

  cout << dp[n-1][k-1];
  return 0;


} 
