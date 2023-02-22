#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N , u , v;
vector<int> inp[1000001];
int dp[1000001][2];
bool visit[1000001];

#define INF 987654321

void dfs(int node){
  dp[node][1] = 1;
  visit[node] = true;

  int next;
  
  for(int i =0; i<inp[node].size() ; i++){
    next = inp[node][i];
    if(!visit[next]){
      dfs(next);
      dp[node][1] +=  min(dp[next][0] , dp[next][1]);
      dp[node][0] += dp[next][1];
    }
  }
  
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;
  
  for(int i =0; i<N-1; i++){
    cin >> u >> v;
    inp[u].push_back(v);
    inp[v].push_back(u);
  }
  
  memset(visit , false ,sizeof(visit));
  memset(dp , 0 , sizeof(dp));
  dfs(1);
  cout << min(dp[1][1] , dp[1][0]);
  return 0;
}
