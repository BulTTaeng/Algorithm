#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v[51];
int inp[51];
int N;
int dp[51];
bool visit[51];


int dfs(int curr){
  vector<int> dnum;

  for(int i =0; i<v[curr].size(); i++){
    dnum.push_back(dfs(v[curr][i]));
  }

  sort(dnum.begin() , dnum.end());

  int maxi =0;

  int seq = v[curr].size();

  for(int i =0; i <dnum.size() ; i++){
    maxi = max(maxi , dnum[i] + seq);
    seq--;
  }

  return maxi;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  memset(dp , 0, sizeof(dp));

  cin >> N;
  int temp;

  cin >> inp[0];
  
  for(int i =1; i<N; i++){
    cin >> inp[i];
    v[inp[i]].push_back(i);
  }

  cout << dfs(0);
  
  return 0;
}
