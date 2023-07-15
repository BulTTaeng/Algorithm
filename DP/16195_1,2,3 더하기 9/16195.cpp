#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long long dp[1002][1002];

vector<int> inp;
vector<int> lim;

#define MOD 1000000009

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , m ,t , maxi = 0;
  
  cin >> t;

  for(int i =0; i<t ; i++){
    cin >> n >> m;
    inp.push_back(n);
    lim.push_back(m);
  }

  memset(dp, 0 , sizeof(dp));

  dp[0][0] = 0;
  
  dp[1][1] = 1;
  
  dp[2][1] = 1;
  dp[2][2] = 1;

  dp[3][1] = 1;
  dp[3][2] = 2;
  dp[3][3] = 1;


  for(int i = 4; i<=1000; i++){
    for(int j =1; j<=1000; j++){
      dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1] + dp[i-3][j-1]) % MOD;
    }
  }

  long long ans = 0;

  for(int i =0; i<t; i++){
    ans = 0;
    for(int j =1; j<=lim[i]; j++){
      ans = (ans + dp[inp[i]][j]) % MOD;
    }
    cout <<ans<<"\n";
  }

  return 0;
}
