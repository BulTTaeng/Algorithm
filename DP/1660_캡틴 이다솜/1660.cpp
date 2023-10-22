#include <iostream>
#include <algorithm>

using namespace std;

int dp[300002];
int num_tri[1002];
int num_b[1002];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n ;
  cin >> n;

  num_tri[0] = 0;
  num_tri[1] = 1;

  num_b[0] = 0;
  num_b[1] = 1;

  int max_b = 0;

  for(int i =2; i<=n; i++){
    num_tri[i] = num_tri[i-1] + i;
    num_b[i] = num_b[i-1] + num_tri[i];
    
    if(num_b[i] > n){
      max_b = i-1;
      break;
    }
  }
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 3;

  for(int i =4; i<=n; i++){
    dp[i] = dp[i-1] + 1;
    for(int j = 1; j<i; j++){
      if(i - num_b[j] >= 0){
        dp[i] = min(dp[i], dp[i-num_b[j]] + 1); 
      }
      else{
        break;
      }
    }
  }

  cout << dp[n];
  return 0;
  
} 
