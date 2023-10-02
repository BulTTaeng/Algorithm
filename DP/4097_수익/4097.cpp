#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[250001];
int input[250001];

vector<int> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  while(true){
    int n;
    cin >> n;

    if(n == 0){
      break;
    }
    
    for(int i =0; i<n; i++){
      cin >> input[i];
    }

    dp[0] = input[0];

    int max_ =-100001;

    for(int i = 1; i<n; i++){
      dp[i] = max(dp[i-1]+input[i] , input[i]);
      if(max_ < dp[i] ){
        max_ = dp[i];
      }
    }

    ans.push_back(max_);

    for(int i =0; i<250001; i++){
      dp[i] = 0;
      input[i] = 0;
    }
    

  }

  for(int i =0; i<ans.size(); i++){
    cout << ans[i]<<endl;
  }

  return 0;
}
