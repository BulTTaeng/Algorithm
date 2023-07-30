#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[2002][2002];
int le[2002];
int ri[2002];

int n;

int find_score(int l , int r);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n;

  for(int i =1; i<=n; i++){
    cin >>le[i];
  }

  for(int i =1; i<=n; i++){
    cin >> ri[i];
  }
  memset(dp, -1, sizeof(dp));

  int ans = find_score(1,1);


  cout << ans;

  return 0;

}

int find_score(int l , int r){

  if(l > n || r > n){
    return dp[l][r] = 0;
  }

  if(dp[l][r] != -1) return dp[l][r];

  if(le[l] > ri[r]){
    dp[l][r] =  find_score(l,r+1) + ri[r];
  }
  else{
    dp[l][r] = max(find_score(l+1, r), find_score(l+1,r+1) );
    
  }
      
  
  return dp[l][r];
}
