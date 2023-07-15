#include <iostream>
#include <vector>

using namespace std;

int dp[10002];

vector<int> inp;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n ,t , maxi = 0;
  cin >> t;

  for(int i =0; i<t; i++){
    cin >> n;
    inp.push_back(n);
    if(maxi < n){
      maxi = n;
    }
  }
  dp[0] = 1;

  for(int i =1; i<=3; i++){
    for(int j = i; j<=maxi; j++){
      dp[j] = dp[j] += dp[j-i];
    }
  
  }

  for(int i =0; i<t; i++){
    cout << dp[inp[i]] << "\n";

  }

  return 0;
}
