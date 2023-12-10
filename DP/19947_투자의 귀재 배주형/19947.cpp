#include <iostream>

using namespace std;

int dp[12];

int find_max(int a , int b);

int main() {
  int H , Y;

  cin >> H >> Y;

  dp[0] = H;


  for(int i = 1; i<=Y; i++){
    dp[i] = dp[i-1] * 1.05;
    if(i>=3) dp[i] = find_max(dp[i] , dp[i-3] * 1.2);
    if(i>=5) dp[i] = find_max(dp[i] , dp[i-5] * 1.35); 
  }

  cout << dp[Y];
  return 0;
}

int find_max(int a , int b){
  if(a>b) return a;
  else return b;
}
