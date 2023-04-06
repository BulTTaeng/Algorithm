#include <iostream>
#include <cstring>

using namespace std;

int N;
int A[22][22];
int x =1,y =1;
int sum[6];
bool sec5[22][22];

int ans = 987654321;

void divideloc(int d1 , int d2){

  int cy = y;
  memset(sec5 ,  false , sizeof(sec5));
  memset(sum, 0 , sizeof(sum));
  
  int mind = min(d1 ,d2);
  int maxd = max(d1,d2);
  int iter = 0;
  int range = 0;
  
  
  for(int i = x; i <= x + d1+d2; i++){
    
    for(int j = cy-range ; j<=cy+range; j++){
      sum[5] += A[i][j];
      sec5[i][j] = true;
    }

    if(iter < mind){
      range++;
    }
    else if(iter >= mind && iter < maxd){
      if(d1 > d2){
        cy--;
      }
      else{
        cy++;
      }
    }
    else{
      range--;
    }
    iter++;
  }

//1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
//2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
//3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
//4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N

  for(int i =1; i<=N; i++){
    for(int j =1; j<=N; j++){

      if(sec5[i][j]) continue;
      
      if(1<=i && i<x+d1 && 1<=j && j<=y){
        sum[1] += A[i][j];
      }
      else if(1<=i && i<=x+d2 && j>y && j<=N){
        sum[2] += A[i][j];
      }
      else if(x+d1 <= i && i<=N && 1 <=j && j<y-d1+d2){
        sum[3] += A[i][j];
      }
      else if(i > x+d2 && i <=N && y-d1+d2 <= j && j<=N){
        sum[4] += A[i][j];
      }
    }
  }

  int mini = sum[1];
  int maxi = sum[1];

  for(int i =2; i<=5; i++){
    mini = min(mini , sum[i]);
    maxi = max(maxi , sum[i]);
  }

  ans = min(ans, maxi - mini);
}

void solve(){

  for(x=1; x<=N; x++){
    for(y=1; y<=N; y++){
      for(int d1 =1; d1<=N; d1++){
        for(int d2 =1; d2<=N; d2++){
    
          if(x+d1+d2 <= N && y-d1 >=1 && y+d2<=N){
            divideloc(d1,d2);
          }
          
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  for(int i =1; i<=N; i++){
    for(int j =1 ; j<=N; j++){
      cin >> A[i][j];
    }
  }

  memset( sum , 0 , sizeof(sum));

  solve();

  cout << ans;
  return 0;
}
