#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> ans;

int dp[100001][3];
int input[100001][3];

int main() {
  int inp;
  int num =1;

  while(true){
    cin >> inp;

    if(inp == 0) break;

    for(int i =0; i<inp; i++){
      for(int j =0; j<3; j++){
        cin >> input[i][j];
      }
    }

    dp[0][0] = input[0][0];
    dp[0][1] = input[0][1];
    dp[0][2] = input[0][2];

    dp[1][0] = input[1][0] + input[0][1];
    
    dp[1][1] = input[1][1] + input[0][1];
    dp[1][1] = min(dp[1][1] ,  input[1][1] + input[0][2] + input[0][1]);
    dp[1][1] = min(dp[1][1] , input[0][1] + input[1][0] + input[1][1]);

    dp[1][2] = input[0][1] + input[1][2];
    dp[1][2] = min(dp[1][2] , input[0][1] + input[0][2] + input[1][2]);
    dp[1][2] = min(dp[1][2] , input[0][1] + input[1][1] + input[1][2]);
    dp[1][2] = min(dp[1][2] , input[0][1] + + input[1][0] + input[1][1] + input[1][2]);

    
    for(int i =2;i<inp; i++){
      
      dp[i][0] = min(dp[i-1][0] + input[i][0] , dp[i-1][1] + input[i][0]);

      dp[i][1] = min(dp[i-1][0] + input[i][1] , dp[i-1][1] + input[i][1]);
      dp[i][1] = min(dp[i][1] , dp[i-1][2] + input[i][1]);
      dp[i][1] = min(dp[i][0] + input[i][1] , dp[i][1]);

      dp[i][2] = min(dp[i-1][1] + input[i][2], dp[i-1][2] + input[i][2]);
      dp[i][2] = min(dp[i][2], dp[i][1] + input[i][2]);
      
    }

    int ans = dp[inp-1][1] ;

    cout << num << ". " << ans << endl;
    num++;

  }

  return 0;
}
