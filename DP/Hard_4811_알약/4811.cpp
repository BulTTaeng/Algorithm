#include <iostream>

using namespace std;

long long dp[32][32];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int inp;

  dp[1][0] = 1;
  dp[0][1] = 1;
  dp[1][1] = 1;
  
  for(int i =1; i<=30; i++){
    dp[i][0] = 1;
    dp[i][1] = i;
  }

  int zero = -1;

  for(int i = 2; i<=30; i++){

    for(int j = 2; j<=i; j++){
      dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    
  }

  while(true){
    cin >> inp;

    if(inp == 0){
      break;
    }
    cout << dp[inp][inp];
    cout <<"\n";
  }

  return 0;

}
