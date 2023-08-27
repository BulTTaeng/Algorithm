#include <iostream>
#include <cstring>

using namespace std;

int dp[252][1001];

int input[1000002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  memset(dp, 0, sizeof(dp));

  dp[1][1] = 1;
  dp[2][1] = 3;

  int to_up = 0;

  for(int i =3 ; i<=250; i++){
    for(int j =1;j<=1000; j ++){
      dp[i][j] = dp[i][j] + dp[i-1][j] + dp[i-2][j]*2;
      to_up = dp[i][j] /10;
      dp[i][j+1] += to_up;
      dp[i][j] = dp[i][j] % 10;
    }
    
  }

  int check =0;

  int n=1;
  while(true){
    cin >> n;
		if (cin.fail() != false) break;

    check = 0;
    if(n == 0) cout << 1;
    else{
      for(int j =1000; j>0; j--){
        if(dp[n][j] == 0 && check == 0){
          continue;
        }
        else{
          check =1;
          cout << dp[n][j];
        }
      }
    }
    
    
    cout <<endl;


  }
  
  return 0;
}
