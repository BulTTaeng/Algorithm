#include <iostream>

using namespace std;

long long dp[1002][10];

int inp[1002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T;

  cin >>T;

  for(int i =1 ; i<=T; i++){
    cin >> inp[i];
  }

  for(int i =0; i<=9; i++){
    dp[1][i] = 1;
  }

  for(int i =2; i<=1000; i++){
    
    for(int j=0; j<=9; j++){
      for(int k =j; k>=0; k--){
        dp[i][j] += dp[i-1][k];
      }
    }

  }

  long long ans =0;

  for(int i =1; i<=T; i++){
    for(int j =0; j<=9; j++){
      ans +=dp[inp[i]][j];
    }
    cout << ans << "\n";
    ans = 0;
  }
  return 0;
}
