#include <iostream>
#include <cstring>

using namespace std;

int N , M;
char inp[51][51];
long long dp[51][51];
bool visit[51][51];
long long ans = 0;

void dfs(int x , int y, long long count){

  if(ans == -1) return;

  if(visit[x][y]) {
    ans = -1;
    return;
  }

  if(dp[x][y] >= count){
    return;
  }

  int num = inp[x][y] - '0';
  
  dp[x][y] = count;
  ans = max(ans , count);
  visit[x][y] = true;

  if(ans != - 1 && x + num < N && inp[x+num][y] != 'H' ){ // 아래
    dfs(x+num , y , count+1);
  }

  if(ans != - 1 && x - num >= 0 && inp[x-num][y] != 'H' ){//위
    dfs(x-num , y , count+1);
  }

  if(ans != - 1 && y + num < M && inp[x][y+num] != 'H'){ //오른쪽
    dfs(x , y + num , count+1);
  }

  if(ans != - 1 && y - num >= 0 && inp[x][y-num] != 'H' ){ //왼쪽
    dfs(x , y - num , count+1); 
  }

  visit[x][y] = false; 
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >>  N >> M;

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      cin >> inp[i][j];
    }
  }
  memset(dp , 0 ,sizeof(dp));
  memset(visit ,false ,sizeof(visit));
  
  dfs(0,0,1);

  cout << ans;
  
  return 0;
}
