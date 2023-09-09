#include <iostream>

using namespace std;

long long dp[1000002];

#define MOD 1000000009

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T , max =0;

  cin >> T;

  int * input = (int*)malloc(sizeof(int) * (T+1));

  for(int i =0; i<T; i++){
    cin >> input[i];
    if(max < input[i]) max = input[i];
  }

  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;

  for(int i =4; i<=max; i++){
    dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
  }

  for(int i =0; i<T ; i++){
    cout << dp[input[i]] <<endl;
  }

  free(input);
  
  return 0;

}
