#include <iostream>
#include <cmath>

using namespace std;

int inp[1002];

int dp[1002];

int main() {
  int N;
  cin >> N;

  for(int i =1 ; i<=N; i++){
    cin >> inp[i];
  }
  dp[0] = 0;
  dp[1] =0;
  dp[2] = abs(inp[2] - inp[1]);

  

  for(int i =3; i<=N; i++){
    dp[i] = dp[i-1];
    int maxi=-999999 , mini = 9999999;
    for(int j =i; j>=1; j--){
      maxi = max(inp[j], maxi);
      mini = min(inp[j], mini);

      dp[i] = max(dp[i] , dp[j-1] + (maxi - mini));
    }
  }
  
  cout << dp[N];
  return 0;

}

