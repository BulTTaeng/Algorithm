#include <iostream>

using namespace std;

long long dp[2][8];

// 0 : 정보과학관
// 1 : 전산관
// 2 : 미래관
// 3 : 신앙관
// 4 : 한경직기념관
// 5 : 진리관
// 6 : 형남 공학관
// 7 : 학생 회관

#define MOD 1000000007

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n ;
  cin >> n;

  dp[0][0] = 1;

  for(int i =1; i<=n; i++){
    dp[i%2][0] = (dp[(i-1)%2][1] + dp[(i-1)%2][2]) % MOD ;
    dp[i%2][1] = (dp[(i-1)%2][0] + dp[(i-1)%2][2] + dp[(i-1)%2][3]) % MOD ;
    dp[i%2][2] = (dp[(i-1)%2][0] + dp[(i-1)%2][1] + dp[(i-1)%2][3] + dp[(i-1)%2][4]) % MOD ;
    dp[i%2][3] = (dp[(i-1)%2][1] + dp[(i-1)%2][2] + dp[(i-1)%2][4] + dp[(i-1)%2][5]) % MOD ;
    dp[i%2][4] = (dp[(i-1)%2][2] + dp[(i-1)%2][3] + dp[(i-1)%2][5] + dp[(i-1)%2][6]) % MOD ;
    dp[i%2][5] = (dp[(i-1)%2][3] + dp[(i-1)%2][4] + dp[(i-1)%2][7]) % MOD ;
    dp[i%2][6] = (dp[(i-1)%2][4] + dp[(i-1)%2][7]) % MOD ;
    dp[i%2][7] = (dp[(i-1)%2][5] + dp[(i-1)%2][6]) % MOD ;

  }

  cout << dp[n%2][0];
  return 0;

} 
