#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> inp;

int N;
int dp[100001][5][5]; //순서, 왼발 , 오른발 위치 일때, 최소값

int costs[5][5] = {
  {2,2,2,2,2},
  {2,1,3,4,3},
  {2,3,1,3,4},
  {2,4,3,1,3},
  {2,3,4,3,1}
};

void dfs(int curr, int l , int r){
  if(curr == N) return;
  if(dp[curr][l][r] != 0) return;

  int loc = inp[curr];

  dfs(curr+1, loc ,r);
  dfs(curr+1, l, loc);

  dp[curr][l][r] = 
    min(dp[curr+1][loc][r]  + costs[l][loc],
        dp[curr+1][l][loc] + costs[r][loc]
    ); 
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  int temp;
  
  while(true){
    cin >> temp;
    if(temp == 0) break;
    
    inp.push_back(temp);
  }

  N = inp.size();
  memset(dp , 0 ,sizeof(dp));

  dfs(0,0,0);

  cout << dp[0][0][0];
  return 0;
}
