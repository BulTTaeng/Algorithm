#include <iostream>
#include <queue>

using namespace std;

int inp[1002];
int exp1[1002];
int exp2[1002];

struct s{
  int v;
  int expv;
  int loc;
  int change;
} typedef s;

queue<s> q;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int T ,W;

  cin >> T >> W;

  for(int i =0; i<T; i++){
    cin >> inp[i];
  }

  exp1[T] = 0;
  exp2[T] = 0;

  for(int i=T-1; i>=0; i--){
    if(inp[i] == 1){
      exp1[i] = exp1[i+1] + 1;
      exp2[i] = exp2[i+1];
    }
    else{
      exp2[i] = exp2[i+1] + 1;
      exp1[i] = exp1[i+1];
    }
   
  }


  s temp;
  
  if(inp[0] == 1){
    temp.v = 1;
    temp.expv = T-1;
    temp.loc = 1;
    temp.change = 0;
    q.push(temp);
  }

  else if(inp[0] == 2){
    temp.v = 0;
    temp.expv = T-1;
    temp.loc = 1;
    temp.change = 0;
    q.push(temp);

    temp.v = 1;
    temp.expv = T-1;
    temp.loc = 2;
    temp.change = 1;
    q.push(temp);
  }

  int max = 0;
  s t;

  while(!q.empty()){
    temp =  q.front();
    q.pop();

    if(temp.v + temp.expv < max){ // 기대치가 지금까지 최대 값 보다 낮음
      continue;
    }

    else{
      if(inp[temp.change] == W){ //더이상 움질일수 없을때
        
        if(temp.loc == 1){
          int a = temp.v + exp1[T - temp.expv+1];

          if(a > max){
            max = a;
          }
        }
        else{
          int a = temp.v + exp2[T - temp.expv+1];

          if(a > max){
            max = a;
          }
        }

      }

      else{ //움직일 수 있을 때
        if(inp[T - temp.expv] == 1){
          if(temp.loc == 1){
            t.v = temp.v + 1;
            t.expv = temp.expv -1;
            t.loc = 1;
            t.change = temp.change;

            q.push(t);
          }
          else{ // == 2
            t.v = temp.v;
            t.expv = temp.expv -1;
            t.loc = 2;
            t.change = temp.change;

            q.push(t);

            t.v = temp.v + 1;
            t.expv = temp.expv -1;
            t.loc = 1;
            t.change = temp.change+1;

            q.push(t);
          }
        }

        else{ //떨어지는 위칙 가 2
          if(temp.loc == 2){
            t.v = temp.v + 1;
            t.expv = temp.expv -1;
            t.loc = 2;
            t.change = temp.change;

            q.push(t);
          }
          else{ // == 1
            t.v = temp.v;
            t.expv = temp.expv -1;
            t.loc = 1;
            t.change = temp.change;

            q.push(t);

            t.v = temp.v + 1;
            t.expv = temp.expv -1;
            t.loc = 2;
            t.change = temp.change+1;

            q.push(t);
          }
        }
      }//움직일 수 있을때
   
    }
  } // end of while

  cout << max;
  return 0;

}
