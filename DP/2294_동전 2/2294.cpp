#include <iostream>
#include <algorithm>

using namespace std;

int dp[10002];

int input[101];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , k;
  cin >> n >> k;

  for(int i =0; i<n; i++){
    cin >>input[i];
  }

  dp[0] = 0;
  
  for(int i =1; i<=k; i++){
    dp[i] = 10009;
    for(int j=0; j<n; j++){
      if(i >= input[j]){
        dp[i] = min(dp[i], dp[i-input[j]] +1);
      }
    }
  }

  if(dp[k] == 10009){
    cout << -1;
  }
  else{
    cout <<dp[k];
  }
  return 0;
}
