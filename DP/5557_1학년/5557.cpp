#include <iostream>
#include <cstring>

using namespace std;

long long dp[102][22];

int inp[102];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin>>n;

  for(int i =0; i<n; i++){
    cin >> inp[i];
  }

  memset(dp,0,sizeof(dp));

  dp[0][inp[0]] = 1;

  for(int i = 1; i<n-1; i++){
    
    for(int j =0; j<=20; j++){
      if(dp[i-1][j] != 0){
        
        if(j + inp[i] <= 20){
          dp[i][j+inp[i]] += dp[i-1][j];
        }

        if(j - inp[i] >= 0){
          dp[i][j-inp[i]] += dp[i-1][j];
        }

      }
    }

  }

  cout << dp[n-2][inp[n-1]];
  return 0;
}
