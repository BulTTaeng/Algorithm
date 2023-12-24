#include <iostream>

using namespace std;

long long dp[31][31];

int main() {
  int R , C, W;
  cin >> R >> C >>W;

  for(int i =0; i<31; i++){
    dp[i][0] =1 ;
    for(int j = 1; j<=i; j++){
      if(j == i){
        dp[i][j] = 1;
      }
      else{
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
      }
      
    }
  }

  long long ans = 0;
  int loc =C-1;

  for(int i =R-1; i<= R+W-2; i++){
    
    for(int j = C-1; j <= loc; j++ ){
      ans += dp[i][j];
    }
    loc++;
  }
  
  cout << ans;
  return 0;

}
