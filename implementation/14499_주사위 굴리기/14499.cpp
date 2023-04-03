#include <iostream>

using namespace std;

int dx[] = {0, 0, 0, -1 , 1};
int dy[] = {0, 1, -1 , 0 ,0};
//동 서 북 남

struct dice{
  int top;
  int r;
  int l;
  int back;
  int front;
  int bottom;
  int x;
  int y;
}typedef dice;

int N, M ,x,y, K;
int board[21][21];
int command[1001];

dice solve(dice d, int c){
  int nx = d.x + dx[c];
  int ny = d.y + dy[c];

  if(nx <0 || ny <0 || nx >= N || ny >= M) return d;

  dice re;
  re.x = nx;
  re.y = ny;

  if(c == 1){ //동
    re.top = d.l;
    re.l = d.bottom;
    re.bottom = d.r;
    re.r = d.top;
    re.front = d.front;
    re.back = d.back;
  }
  else if(c == 2){ //서
    re.top = d.r;
    re.r = d.bottom;
    re.bottom = d.l;
    re.l = d.top;
    re.front = d.front;
    re.back = d.back;
  }
  else if(c == 3){//북
    re.top = d.front;
    re.front = d.bottom;
    re.bottom = d.back;
    re.back = d.top;
    re.r = d.r;
    re.l = d.l;
  }
  else{//남
    re.top = d.back;
    re.back = d.bottom;
    re.bottom = d.front;
    re.front = d.top;
    re.r = d.r;
    re.l = d.l;
  }

  if(board[nx][ny] == 0){
    board[nx][ny] = re.bottom;
  }
  else{
    re.bottom = board[nx][ny];
    board[nx][ny] = 0;
  }

  cout << re.top <<"\n";
  return re;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M >> x >> y >> K;

  for(int i =0; i<N;i++){
    for(int j=0; j<M; j++){
      cin >> board[i][j];
    }
  }

  for(int i =0; i<K; i++){
    cin >> command[i];
  }

  dice d;
  d.top = 0;
  d.bottom = 0;
  d.back = 0;
  d.front = 0;
  d.r = 0;
  d.l = 0;
  d.x = x;
  d.y = y;

  dice newdice;
  
  for(int i =0; i<K; i++){
    newdice = solve(d , command[i]);
    d =newdice;
  }
  
  return 0;
}
