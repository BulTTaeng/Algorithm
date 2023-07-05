#include <iostream>

using namespace std;

int dp[31];

int main() {
  int n ;
  cin>> n;
  dp[0] = 1;
  dp[1] =1;

  for(int i = 2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2] *2;
  }

  
  if(n%2 == 0){
    dp[n] = dp[n] - ( (dp[n] - (dp[n/2] + dp[(n-2) /2]*2 )) /2 );
  }
  else{
    dp[n] = dp[n] - ( (dp[n] - ( dp[(n-1) / 2] ) ) / 2);
  }
  

  cout << dp[n];

  return 0;
}
