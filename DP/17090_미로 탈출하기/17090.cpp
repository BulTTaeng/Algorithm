#include <iostream>
#include <cstring>

using namespace std;

int N,M;
int map[501][501];
bool canEscape[501][501];
bool visit[501][501];
int ans =0;

int dx[] = {-1, 0 , 1 , 0};
int dy[] = {0, 1, 0, -1};


bool dfs(int r , int c){
  
  //해당 위치에서 탈출할 수 있는 루트를 이전에 발견했으면 탈출 가능
  if(canEscape[r][c]) return true;
  //해당 위치를 방문해서 탐색을 했는데 탈출할 수 있는 루트가 없는 경우
  else{
    if(visit[r][c]) return false;
  }

  visit[r][c] = true;
  
  int dir = map[r][c];

  int nx = r + dx[dir];
  int ny = c +dy[dir];

  //탈출 가능!
  if(nx >=N || ny >=M || nx <0 || ny< 0){
    return canEscape[r][c] = true;
  }
  else{
    //탈출 가능 여부 기록!
    return canEscape[r][c] = dfs(nx,ny);
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  char ctemp;

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      cin >> ctemp;
      if(ctemp == 'U'){
        map[i][j] = 0;
      }
      else if(ctemp == 'R'){
        map[i][j] = 1;
      }
      else if(ctemp == 'D'){
        map[i][j] = 2;
      }
      else{
        map[i][j] = 3;
      }
    }
  }

  memset(canEscape , false, sizeof(canEscape));
  memset(visit , false , sizeof(visit));

  bool ok = false;

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      ok = dfs(i,j);
      if(ok){
        ans++;
      }
    }
  }

  cout << ans;
  return 0;
}
