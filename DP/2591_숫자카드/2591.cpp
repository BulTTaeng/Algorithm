#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

queue<int> loc;
vector<int> inp;

int dp[43];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  string n;

  cin >> n;

  inp.push_back(99999);

  for(int  i= 0; i<n.size(); i++){
    inp.push_back(n[i] - '0');
  }

  memset(dp, 0 , sizeof(dp));

  dp[0] = 1;
  dp[1] = 1;

  for(int i =2 ; i<=n.size(); i++){

    if(inp[i] == 0){
      dp[i] = dp[i-2];
    }

    else{
        if(inp[i-1] *10 + inp[i] <=34 && inp[i-1] *10 + inp[i] >=10){
          dp[i]= dp[i-1] + dp[i-2]; 
        }
        else{
          dp[i] = dp[i-1];
        }

    }

  }

  /*for(int i =0; i<=n.size(); i++){
    cout << dp[i] << " ";
  }*/

  cout << dp[n.size()];
  return 0;

}
