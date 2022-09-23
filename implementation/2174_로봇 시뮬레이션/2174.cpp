#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct robot{
  int x;
  int y;
  char dir;
}typedef robot;

//1 동 2 서 3 남 4북

struct command{
  int rnum;
  char opt;
  int times;
}typedef cm;

int A,B, N , M;
int state =-1;
int problemR = -1;
int meetRobot = -1;
int board[102][102];
robot robots[102];
vector<cm> v;

int moveFront(int t , int rn);
int checkp(int rn);
void showBoard();
void turnLeft(int t , int rn);
void turnRight(int t , int rn);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> A >> B;
  cin >> N >> M;
  memset(board , 0 ,sizeof(board));
  
  int x,y;
  char d;
  int rnum , times;
  char opt;

  robot temp;
  cm temp2;
  
  for(int i =1; i<=N; i++){
    cin >> x >> y >> d;
    temp.x = x;
    temp.y = B-y+1;
    temp.dir = d;
    board[temp.y][temp.x] = i;
    robots[i] = temp;
  }

  for(int i=1; i<=M; i++){
    cin >> rnum >> opt >> times;
    temp2.rnum = rnum;
    temp2.opt = opt;
    temp2.times = times;
    v.push_back(temp2);
  }
  
  for(int i =0; i<v.size(); i++){
    
    if(v[i].opt == 'F'){
      state = moveFront(v[i].times ,v[i].rnum);
    }
    else if(v[i].opt == 'R'){
      turnRight(v[i].times , v[i].rnum);
    }
    else if(v[i].opt == 'L'){
      turnLeft(v[i].times , v[i].rnum);
    }
    if(state == 1 || state == 2){ // 벽 or 다른 로봇
      problemR = v[i].rnum;
      break;
    }
  }

  if(state == 1){
    cout << "Robot "<<problemR <<" crashes into the wall";
  }
  else if(state == 2){
    cout << "Robot "<<problemR <<" crashes into robot " << meetRobot;
  }
  else{
    cout << "OK";
  }
  return 0;
}

int moveFront(int t , int rn){

  board[robots[rn].y][robots[rn].x] = 0;
  int cases;
  
  for(int i =0; i<t; i++){
    if(robots[rn].dir == 'E'){ // 동
      robots[rn].x++;
    }
    else if(robots[rn].dir == 'W'){ // 서
      robots[rn].x--;
    }
    else if(robots[rn].dir == 'S'){ // 남
      robots[rn].y++;
    }
    else if(robots[rn].dir == 'N'){ // 북
      robots[rn].y--;
    }

    cases = checkp(rn); //부딪히는지 문제가 없는지 체크
    
    if(cases != 3){ //문제가 있다면!
      break;
    }
  }

  if(cases == 3){
    board[robots[rn].y][robots[rn].x] = rn;
  }

  return cases;
}

void turnRight(int t , int rn){

  int movetimes = t%4;

  if(robots[rn].dir == 'E'){ // 동
      switch(movetimes){
        case(0):
          robots[rn].dir ='E';
          break;
        case(1):
          robots[rn].dir ='S';
          break;
        case(2):
          robots[rn].dir ='W';
          break;
        case(3):
          robots[rn].dir ='N';
          break;
      }
    }
    else if(robots[rn].dir == 'W'){ // 서
      switch(movetimes){
        case(0):
          robots[rn].dir ='W';
          break;
        case(1):
          robots[rn].dir ='N';
          break;
        case(2):
          robots[rn].dir ='E';
          break;
        case(3):
          robots[rn].dir ='S';
          break;
      }
    }
    else if(robots[rn].dir == 'S'){ // 남
      switch(movetimes){
        case(0):
          robots[rn].dir ='S';
          break;
        case(1):
          robots[rn].dir ='W';
          break;
        case(2):
          robots[rn].dir ='N';
          break;
        case(3):
          robots[rn].dir ='E';
          break;
      }
    }
    else if(robots[rn].dir == 'N'){ // 북
      switch(movetimes){
        case(0):
          robots[rn].dir ='N';
          break;
        case(1):
          robots[rn].dir ='E';
          break;
        case(2):
          robots[rn].dir ='S';
          break;
        case(3):
          robots[rn].dir ='W';
          break;
      }
    }
}


void turnLeft(int t , int rn){

  int movetimes = t%4;

  if(robots[rn].dir == 'E'){ // 동
      switch(movetimes){
        case(0):
          robots[rn].dir ='E';
          break;
        case(1):
          robots[rn].dir ='N';
          break;
        case(2):
          robots[rn].dir ='W';
          break;
        case(3):
          robots[rn].dir ='S';
          break;
      }
    }
    else if(robots[rn].dir == 'W'){ // 서
      switch(movetimes){
        case(0):
          robots[rn].dir ='W';
          break;
        case(1):
          robots[rn].dir ='S';
          break;
        case(2):
          robots[rn].dir ='E';
          break;
        case(3):
          robots[rn].dir ='N';
          break;
      }
    }
    else if(robots[rn].dir == 'S'){ // 남
      switch(movetimes){
        case(0):
          robots[rn].dir ='S';
          break;
        case(1):
          robots[rn].dir ='E';
          break;
        case(2):
          robots[rn].dir ='N';
          break;
        case(3):
          robots[rn].dir ='W';
          break;
      }
    }
    else if(robots[rn].dir == 'N'){ // 북
      switch(movetimes){
        case(0):
          robots[rn].dir ='N';
          break;
        case(1):
          robots[rn].dir ='W';
          break;
        case(2):
          robots[rn].dir ='S';
          break;
        case(3):
          robots[rn].dir ='E';
          break;
      }
    }
}

int checkp(int rn){ //1 -> 벽 , 2-> 다른 로봇 3-> ok

  if(robots[rn].x >A || robots[rn].y> B || robots[rn].x <1 || robots[rn].y < 1){
    return 1;    
  }
  else if(board[robots[rn].y][robots[rn].x] != 0){
    meetRobot = board[robots[rn].y][robots[rn].x];
    return 2;
  }
  else{
    return 3;
  }
}

void showBoard(){
  for(int i =1; i<=B; i++){
    for(int j =1; j<=A; j++){
      cout << board[i][j] <<" ";
    }
    cout << "\n";
  }

  cout <<"\n";
}
