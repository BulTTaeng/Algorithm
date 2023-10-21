#include <iostream>

using namespace std;

int dp[1002];
int input[1002];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int t , n;

  int max = 0;

  cin>> t;

  for(int i =1; i<=t; i++){
    cin >> input[i];
    if(max < input[i]){
      max = input[i];
    }
  }

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 2;
  dp[4] = 4;

  for(int i =5; i<=max ;i++){
    dp[i] = dp[i-2] + dp[i/2];
  }

  for(int i =1;i<=t; i++){
    cout << dp[input[i]] << endl;
  }
  return 0;


}
