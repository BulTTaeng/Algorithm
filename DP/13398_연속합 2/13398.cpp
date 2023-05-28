#include <iostream>

using namespace std;

int dp[100002];
int dp_1[100002];

int inp[100002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n ;

  cin >> n;

  for(int i =0; i<n; i++){
    cin >> inp[i];
  }

  int ans = inp[0];

  dp[0] =inp[0];
  dp_1[0] = inp[0];

  for(int i = 1; i<n; i++){
    dp[i] = max(inp[i] , inp[i] + dp[i-1]);
    dp_1[i] = max(dp_1[i-1] + inp[i], dp[i-1]);

    ans = max(ans, max(dp[i] , dp_1[i]));

  }

  cout << ans;
  return 0;

}
