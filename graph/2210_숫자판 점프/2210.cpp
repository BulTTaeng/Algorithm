#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int inp[5][5];
bool check[1000000];
int ans = 0;

void DFS(int x , int y , int num , int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    for(int i=0; i<5; i++){
        for(int j =0; j<5; j++){
            cin >>inp[i][j];
        }
    }

    memset(check , false , sizeof(check));

    for(int i =0; i<5 ; i++){
        for(int j =0; j<5; j++){
            DFS(i,j,0, 0);
        }
    }

    cout <<ans;
    return 0;
}

void DFS(int x , int y , int num , int d){
    
    if(d == 6){
      if(check[num] == true){
          return;
      }
      else{
          ans++;
          check[num] = true;
          return;
      }
    }

    if(x>=1){
        DFS(x-1 , y, num*10 +inp[x][y] , d+1);
    }
    if(y>=1){
        DFS(x , y-1,  num*10 +inp[x][y] , d+1);
    }
    if(x<4){
        DFS(x+1 , y,  num*10 +inp[x][y] , d+1);
    }
    if(y<4){
        DFS(x , y+1,  num*10 +inp[x][y] , d+1);
    }
    return;
}
