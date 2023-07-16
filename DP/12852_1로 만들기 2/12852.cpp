#include <iostream>
#include <queue>

using namespace std;

int dp[1000002];
int pre[1000002];


void find_ans(int num);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  dp[1]= 0;
  pre[1] =1;
  dp[2] = 1;
  pre[2] = 1;
  dp[3] = 1;
  pre[3] =1;

  for(int i =4; i<=n; i++){
    dp[i] = dp[i-1] +1;
    pre[i] = i-1; 
    if(i % 3 == 0) {
      if(dp[i] > dp[i/3] +1){
        dp[i] = dp[i/3] +1;
        pre[i] = i/3;
      }
    }

    if(i % 2 == 0) {
      if(dp[i] > dp[i/2] +1){
        dp[i] = dp[i/2] +1;
        pre[i] = i/2; 
      }
    }
    
  }
  cout << dp[n] << "\n";
  find_ans(n);
  return 0;


}


void find_ans(int num){
  if(num <1){
    return;
  }
  if(num == 1){
    cout << num << " ";
    return;
  }
  cout << num << " ";
  find_ans(pre[num]);
}
