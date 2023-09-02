#include <iostream>
#include <cstring>

using namespace std;

struct vol{
  int num;
  int volume;
}typedef vol;

int input[52];

bool dp[52][1002];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N , S ,M;

  cin >> N >> S >> M;

  for(int i =1 ; i<=N ;i++){
    cin >> input[i];
  }
  
  memset(dp , false , sizeof(dp));

  if(S + input[1] <=M) dp[1][S+input[1]] = true;
  if(S- input[1] >= 0) dp[1][S-input[1]] = true; 
  
  for(int i =2; i<=N; i++){
    for(int j =0; j<=M; j++){
      if(dp[i-1][j] == true){
        if(j + input[i] <=M) dp[i][j+input[i]] = true;
        if(j- input[i] >= 0) dp[i][j-input[i]] = true;
      }
    }
  }

  int ans = -1;

  for(int i =0; i<=M; i++){
    if(dp[N][i] == true){
      if(ans < i){
        ans = i;
      }
    }
  }

  cout << ans;
  return 0;
}
