#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
int inp[5][5];
int ans = 0;

int findCol(int col){
  int temp = 0;
  
  for(int j =0; j<M; j++){
    temp +=  (inp[col][j] * pow(10, M-j-1)) ;
  }

  return temp;
}

int findRow(int row){
  int temp =0;
  
  for(int j =0; j<N; j++){
    temp +=  (inp[j][row] * pow(10, N-j-1)) ;
  }  

  return temp;
}

void solve(){

  int idx;
  int sum =0;
  int temp;
  
  for(int bit = 0; bit <(1<<(N*M)); bit++){
    sum = 0;
    temp = 0;

    //가로로 묶은 곳 연산
    for(int i =0; i<N; i++){

      for(int j =0; j<M; j++){
        idx = i*M+j;

        if((bit & (1 << idx)) == 0){
          temp = temp*10 + inp[i][j];
        }
        else{
          sum += temp;
          temp = 0;
        }
        
      }
      sum += temp;
      temp = 0;
    }


    //세로 연산
    for(int i =0; i<M; i++){
      
      for(int j =0; j<N; j++){
        idx = j*M+i;

        if((bit & (1 << idx)) != 0){
          temp = temp*10 + inp[j][i];
        }
        else{
          sum += temp;
          temp = 0;
        }
        
      }
      sum += temp;
      temp = 0;
    }

    ans = max(sum , ans);
    sum =0;
    temp = 0;
  }
  
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  char c;

  for(int i =0; i<N; i++){
    for(int j =0; j<M; j++){
      cin >> c;
      inp[i][j] = c -'0';
    }
  }
  

  solve();
  cout << ans;
  return 0;
}
