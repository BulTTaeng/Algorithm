#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int inp[4][4];
bool visit[4][4];
queue<pair<int , int>> q;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n ;
  cin >> n;

  for(int i = 1 ; i<=n; i++){
    for(int j = 1; j<=n; j++){
      cin >> inp[i][j];
    }
  }

  memset(visit, false , sizeof(visit));

  q.push(make_pair(1,1));
  visit[1][1] = true;
  
  bool possible = false;
  int x , y;
  
  while(!q.empty()){
    
    if(visit[n][n]){
      possible = true;
      break;
    }

    pair<int , int> temp = q.front();
    q.pop();

    if(temp.first + inp[temp.first][temp.second] <= n && inp[temp.first][temp.second] != -1 ){
      x = temp.first + inp[temp.first][temp.second];
      if(!visit[x][temp.second]){
        q.push(make_pair(x, temp.second));
        visit[x][temp.second] = true;
      }
        
    }

    if(temp.second + inp[temp.first][temp.second] <= n && inp[temp.first][temp.second] != -1){
      y = temp.second + inp[temp.first][temp.second];
      if(!visit[temp.first][y]){
        q.push(make_pair(temp.first, y));
        visit[temp.first][y] = true;
      }
    }

  }

  if(possible)
    cout << "HaruHaru";
  else
    cout << "Hing";
  
  return 0;
}
