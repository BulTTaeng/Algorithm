#include <iostream>
#include <cstring>

using namespace std;

int N, M , K;

int board[22][22];
bool visit[22][22];

int dx[] = {0,0,1,-1}; //동 서 남 북
int dy[] = {1,-1,0,0};

int ans = 0;

struct dice{
  int top;
  int bottom;
  int r;
  int l;
  int f;
  int b;
  int dir;
  int x;
  int y;
}typedef dice;

dice firstDice;

void getScore(int num , int x , int y){

  visit[x][y] = true;
  ans += num;

  for(int i =0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx <=0 || ny <= 0 || nx > N || ny > M) continue;

    if(!visit[nx][ny] && board[nx][ny] == num){
      getScore(num , nx, ny);
    }
    
  }
}

void moveDice(dice di){

  dice newDice;
  
  newDice.x = di.x + dx[di.dir];
  newDice.y = di.y + dy[di.dir];

  if(newDice.x <=0 || newDice.y <= 0 || newDice.x > N || newDice.y > M){
    if(di.dir == 0){
      newDice.x = di.x +dx[1];
      newDice.y = di.y + dy[1];
      di.dir = 1;
    }
    else if(di.dir == 1){
      newDice.x = di.x +dx[0];
      newDice.y = di.y + dy[0];
      di.dir = 0;
    } 
    else if(di.dir == 2){
      newDice.x = di.x +dx[3];
      newDice.y = di.y + dy[3];
      di.dir = 3;
    }
    else{ 
      newDice.x = di.x +dx[2];
      newDice.y = di.y + dy[2];
      di.dir = 2;
    }
  }

  newDice.dir = di.dir;

  if(di.dir == 0){ //동
    newDice.r = di.top;
    newDice.bottom = di.r;
    newDice.top = di.l;
    newDice.l = di.bottom;
    newDice.f = di.f;
    newDice.b = di.b;
  }
  else if(di.dir == 1){ //서
    newDice.r = di.bottom;
    newDice.bottom = di.l;
    newDice.top = di.r;
    newDice.l = di.top;
    newDice.f = di.f;
    newDice.b = di.b;
  }
  else if(di.dir == 2){ //남
    newDice.r = di.r;
    newDice.l = di.l;
    newDice.bottom = di.f;
    newDice.top = di.b;
    newDice.f = di.top;
    newDice.b = di.bottom;
  }
  else{ //북
    newDice.r = di.r;
    newDice.l = di.l;
    newDice.bottom = di.b;
    newDice.top = di.f;
    newDice.f = di.bottom;
    newDice.b = di.top;
  }
  
  memset(visit ,false, sizeof(visit));
  getScore(board[newDice.x][newDice.y] , newDice.x , newDice.y);

  if(newDice.bottom > board[newDice.x][newDice.y]){
    if(newDice.dir == 0) newDice.dir = 2;
    else if(newDice.dir == 1) newDice.dir = 3;
    else if(newDice.dir == 2) newDice.dir =1;
    else newDice.dir = 0;
  }
  else if(newDice.bottom < board[newDice.x][newDice.y]){
    if(newDice.dir == 0) newDice.dir = 3;
    else if(newDice.dir == 1) newDice.dir = 2;
    else if(newDice.dir == 2) newDice.dir =0;
    else newDice.dir = 1;
  }

  firstDice = newDice;
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M >> K;

  for(int i =1; i<=N; i++){
    for(int j =1; j<=M; j++){
      cin >> board[i][j]; 
    }
  }

  
  firstDice.top = 1;
  firstDice.bottom = 6;
  firstDice.f = 5;
  firstDice.b = 2;
  firstDice.r = 3;
  firstDice.l = 4;
  firstDice.dir = 0;
  firstDice.x = 1;
  firstDice.y = 1;


  for(int i =0; i<K; i++){
    moveDice(firstDice);
  }

  cout << ans;
  return 0;
}
