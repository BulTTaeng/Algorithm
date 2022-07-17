#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int N , T;

int dp[46];
stack<int> ans;

int fibo(int num);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> T;

  memset(dp , 0, sizeof(dp));

  dp[1] = 1;
  dp[2] = 1;  

  fibo(45);

  while(T--){
    cin >> N;

    for(int i = 45 ; i>=0; i--){
      if(N >= dp[i]){
        ans.push(dp[i]);
        N -= dp[i];
      }

      if(N ==0){
        break;
      }
    }

    while(!ans.empty()){
      cout << ans.top() << " ";
      ans.pop();
    }
    cout << "\n";
  }

  return 0;
}

int fibo(int num){
  if(dp[num] != 0){
    return dp[num];
  }
  else if(num == 0){
    return 0;
  }
  else {
    return dp[num] = fibo(num-1) + fibo(num-2);
  }
}
