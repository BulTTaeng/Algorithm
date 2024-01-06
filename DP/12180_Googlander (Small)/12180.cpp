#include <iostream>
#include <vector>

using namespace std;

vector<int> x;
vector<int> y;

int dp[12][12];

int main() {
  int T , input1 ,input2;

  cin >> T;

  for(int i =0 ; i<T; i++){
    cin >> input1 >> input2;
    x.push_back(input1);
    y.push_back(input2);
  }

  for(int i =1; i<11; i++){
    for(int j=1; j<11; j++){
      if(i == 1 || j == 1){
        dp[i][j] = 1;
      }
      else{
        dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
  }

  for(int i =0; i<T; i++){
    cout<< "Case #" << i+1 << ": " << dp[x[i]][y[i]] << endl;
  }
  return 0;
} 
