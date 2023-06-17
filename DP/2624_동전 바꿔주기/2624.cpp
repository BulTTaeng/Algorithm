#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[102][10002];

struct{
  int p;
  int n;
}typedef s;

vector<s> inp;

bool compare(const s& s1 , const s& s2){
  return s1.p < s2.p;
}

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int t , k;

  cin >> t >> k;

  s temp;

  for(int i =0; i<k ; i++){
    cin >> temp.p >> temp.n;
    inp.push_back(temp);
  }

  memset(dp, 0, sizeof(dp));

  dp[0][0] = 1;

  sort(inp.begin(), inp.end(), compare);

  for(int i =1; i<=inp[0].p * inp[0].n; i++){
    if(i % inp[0].p == 0){
      dp[0][i] = 1;
    }
  }

  for(int i= 1; i<k; i++){
    
    dp[i][0] = 1;

    for(int j =0; j<=t; j++){
      
      if(dp[i-1][j] != 0){

        for(int q = 1; q<= inp[i].n ; q++){
          if(q * inp[i].p + j < t+1)
            dp[i][j + q * inp[i].p] += dp[i-1][j];
        }
      }

      if(j != 0)
        dp[i][j] += dp[i-1][j];
    }

  }

 /* for(int i =0; i<k; i++){

    for(int j =1 ; j<=t ; j++){
      cout << dp[i][j]<<" ";
    }
    cout << "\n";
  }*/
  

  cout <<dp[k-1][t];
  return 0;

}
