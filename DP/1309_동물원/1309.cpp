#include <iostream>

using namespace std;

int dp[100002];

#define MOD 9901

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n ;
  cin >> n;

  dp[1] = 3;
  dp[2] = 7;

  for(int i =3; i<=n; i++ ){
    dp[i] = (dp[i-1] *2 + dp[i-2]) % MOD ;
  }

  cout <<dp[n];
  return 0;
}
