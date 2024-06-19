#include <iostream>

using namespace std;

int dp[16][16];

int main() {
  string phone1 , phone2;

  cin >> phone1 >> phone2;

  int t =0;

  for(int i =0; i<16; i+=2){
    dp[0][i] = phone1[t] - '0';
    dp[0][i+1] = phone2[t] - '0';
    t++;
  }

  for(int i =1; i<16; i++){
    for(int j =0; j <16-i; j++){
      dp[i][j] = (dp[i-1][j] + dp[i-1][j+1]) % 10;
    }
  }

  cout << dp[14][0] << dp[14][1];
  return 0;
} 
