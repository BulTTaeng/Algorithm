#include <iostream>

using namespace std;

int dp[1002];

#define SK 1
#define CY 0

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n ;
  cin >> n;

  dp[1] = SK;
  dp[2] = CY;
  dp[3] = SK;
  dp[4] = SK;
  
  int temp;

  for(int i =5; i<=n; i++){
    temp = dp[i-1] + dp[i-3] + dp[i-4];
    if(temp == 3){
      dp[i] =CY;
    }
    else{
      dp[i] = SK;
    }
  }
  if(dp[n] == 1){
    cout << "SK";
  }
  else{
    cout << "CY"; 
  }

  return 0;
}
