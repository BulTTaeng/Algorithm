#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int input[5][100002];
int dp[2][100003];

vector<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , a; 
  cin >> n ; 

  for(int i = 0; i<n; i++){
    
    memset(input, 0, sizeof(input));
    memset(dp, 0, sizeof(dp));
    
    for(int j =0 ; j<5 ; j++){
      cin >> input[0][j];
    }

    for(int j =1 ; j<5; j++){
      for(int k =0; k < input[0][0]-1; k++){
        cin >> input[j][k];
      }
    }

    dp[0][0] = input[0][1]; // s1
    dp[1][0] = input[0][2]; // s2

    for(int j = 1; j<input[0][0]; j++){
      dp[0][j] = min(dp[1][j-1] + input[3][j-1] , dp[0][j-1] + input[2][j-1]); 

      dp[1][j] = min(dp[0][j-1] + input[1][j-1] , dp[1][j-1] + input[4][j-1]);
    }

    dp[0][input[0][0]] = dp[0][input[0][0]-1] + input[0][3];
    dp[1][input[0][0]] = dp[1][input[0][0]-1] + input[0][4];

    a = min(dp[0][input[0][0]] , dp[1][input[0][0]]);

    ans.push_back(a);
  }

  for(int i =0; i<ans.size(); i++){
    cout << ans[i] << endl;
  }

  return 0;
}

