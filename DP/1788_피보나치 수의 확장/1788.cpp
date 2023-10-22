#include <iostream>
#include <math.h>

using namespace std;

long long dp[1000002];

int main() {
  int n ;
  cin >> n;

  dp[0] = 0;
  dp[1] = 1;

  if(n == 0){
    cout <<0 << endl;
    cout << 0;
    return 0;
  }

  else if(n >0 ){
    dp[2] = 1;

    for(int i =3; i<=n;i++){
      dp[i] = (dp[i-1] + dp[i-2]) % 1000000000;
    }

    cout << 1 << endl;
    cout << dp[n];
    return 0;
  }

  else{
    n = abs(n);
    dp[2] = -1;

    for(int i=3; i<=n; i++){
      dp[i] = (dp[i-2] - dp[i-1]) % 1000000000;
    }

    if(dp[n] < 0){
      cout << -1 <<endl;
      cout<<abs(dp[n]);
      return 0;
    }
    else if (dp[n] ==0){
      cout << 0 << endl;
      cout << 0;
      return 0;
    }
    else{
      cout << 1 <<endl;
      cout << dp[n];
      return 0;
    }

  }

} 
