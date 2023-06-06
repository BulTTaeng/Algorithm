#include <iostream>
#include <cstring>

using namespace std;

int inp[22];
int dp[10002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T , n, m; 

  cin >> T;

  for(int i =0; i<T; i++){
    cin >> n;

    memset(inp, 0 , sizeof(inp));
    memset(dp, 0, sizeof(dp));

    for(int j =0;j<n; j++){
      cin >> inp[j];
    }

    cin >>m;
    
    dp[0] = 1;

    for(int j=0; j<n; j++){
      for(int k=inp[j]; k<=m; k++){
        dp[k] +=dp[k-inp[j]];
      }
    }

    /*for(int k=1; k<=m; k++){
      cout << dp[k] << " ";
    }
    cout <<"\n";*/

    cout << dp[m] << "\n";
  }

  return 0;
}
