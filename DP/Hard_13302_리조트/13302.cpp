#include <iostream>
#include <cstring>

using namespace std;

int dp[102][102];

bool rest[102];

int n , m;

int dfs(int day , int coupon);

#define MAX 1000003

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int t;
  cin >> n >> m;

  memset(rest, false, sizeof(rest));
  for (int i = 1; i <= n; i++)
  {
      for (int j = 0; j <= n; j++)
      {
        dp[i][j] = MAX;
      }
  }

  for(int i =0; i<m; i++){
    cin >> t;
    rest[t] = true;
  }

  int ans = dfs(1,0);
  cout<< ans;
  return 0;
}

int dfs(int day , int coupon){

  if(day > n) return 0;
  if(dp[day][coupon] != MAX) return dp[day][coupon];
  if(rest[day] == true){
    return dp[day][coupon] = dfs(day+1, coupon);
  }

  dp[day][coupon] = min(dp[day][coupon] , dfs(day+1, coupon) + 10000);
  dp[day][coupon] = min(dp[day][coupon] , dfs(day+3, coupon+1) + 25000);
  dp[day][coupon] = min(dp[day][coupon] , dfs(day+5, coupon+2) + 37000);

  if (coupon >= 3) dp[day][coupon] = min(dp[day][coupon], dfs(day + 1, coupon - 3));
 
  return dp[day][coupon];

}
