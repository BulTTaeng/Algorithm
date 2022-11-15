#include <iostream>
#include <cstring>

using namespace std;

int N , K;
int dp[1002][1002];

#define MOD 1000000003

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >>  N >> K;

  solve();

  cout << dp[N][K];
  return 0;
}

void solve(){

  memset(dp , 0 , sizeof(dp));
  
  for(int i =1; i<=N; i++){
    dp[i][1] = i;
  }

  for(int k =2; k<=K; k++){
    for(int n = k*2; n<=N; n++){
      if(n == k*2) dp[n][k] = 2;
      else{
        dp[n][k] = (dp[n-1][k] + dp[n-2][k-1] ) % MOD;
      }
    }
  }
}
