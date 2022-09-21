#include <iostream>
#include <cstring>

using namespace std;

char inp[10001][501];
bool visit[10001][501];
int R , C;

int dx[] = {-1, 0, 1};

int ans = 0;
bool reached = false;

void dfs(int r ,int c);


int main() {
  ios_base::sync_with_stdio(false);
  

  cin >> R >> C;

  for(int i =0; i<R; i++){
    for(int j =0; j<C; j++){
      cin >> inp[i][j];
    }
  }

  memset(visit , false ,sizeof(visit));
  
  for(int i =0; i<R; i++){
    reached = false;
    dfs(i , 0);
  }

  cout << ans;
  return 0;
}

void dfs(int r ,int c){
  
  visit[r][c] = true;
  
  if(c == (C-1)){
    ans++;
    reached = true;
    return;
  }
  
  int ny = c +1;
  
  for(int i =0; i<3; i++){
    int nx = r+dx[i];

    if(nx>=0 && ny>=0 && nx<R && ny<C){
      if(!visit[nx][ny] && inp[nx][ny] == '.'){
        dfs(nx , ny);
        if(reached) return;
      }
    }
    
  }
  
}
