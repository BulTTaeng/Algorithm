#include <iostream>

using namespace std;

long long dp[102];
long long buffer[102];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin>>n;
  int t =2;

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;
  dp[4] = 4;
  dp[5] = 5;
  dp[6] = 6;

  buffer[1] =0;
  buffer[2] =0;
  buffer[3] =0;
  buffer[4] =0;
  buffer[5] =0;
  buffer[6] =3;


  for(int i =7; i<=n; i++){
    dp[i] = i;
    t=2;
    for(int j= i-3; j>=1; j--){
      if(dp[i] < dp[j] *t ){
        buffer[i] = buffer[j];
        dp[i] = dp[j] * t;
      }
      t++;
    }

    t =2;
    for(int j= i-1; j>=1; j--){
      dp[i] = max(dp[i] , buffer[j] * t);
      t++;
    }

  }

  cout << dp[n];
  return 0;

}
