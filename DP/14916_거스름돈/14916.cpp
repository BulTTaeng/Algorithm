#include <iostream>

using namespace std;

int dp[100002];

int find_min(int a , int b);

int main() {
  int n;
  cin >> n;

  dp[1] = -1;
  dp[2] = 1;
  dp[3] = -1;
  dp[4] = 2;
  dp[5] = 1;

  for(int i = 6; i<=n ; i++){
    dp[i] = find_min(dp[i-2]+1 , dp[i-5]+1);
  }

  cout << dp[n];
  return 0;
}

int find_min(int a, int b){
  if(a == 0 && b == 0) return -1;
  else if(a == 0) return b;
  else if (b == 0) return a;
  else if(a>b) return b;
  else return a;
}
