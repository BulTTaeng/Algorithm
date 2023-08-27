    #include <iostream>

using namespace std;

int dp[5002];

int inp[5002];

#define MOD 1000000

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string n ;
  cin >> n;

  for(int i =0; i < n.size(); i++){
    inp[i+1] = n[i] - '0';
  }

  if(inp[1] <= 0){
    cout << 0;
    return 0;
  }
  else{
    dp[0] = 1;
    dp[1] = 1;
  }
  
  for(int i =2; i<=n.size(); i++){

    if(inp[i-1] * 10 + inp[i] <= 26 && inp[i-1] * 10 + inp[i] >= 10){
      if(inp[i] == 0){
        dp[i] = dp[i-2];
      }
      else{
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
      }
      
    }

    else if(inp[i] >=1 && inp[i] <=9){
      dp[i] = (dp[i] + dp[i-1]) % MOD;
    }
      

  }

  /*for(int i =1; i<=n.size(); i++){
    cout << dp[i] << " ";
  }*/

  cout<< dp[n.size()];
  return 0;
}
