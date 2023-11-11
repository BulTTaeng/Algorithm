#include <iostream>
#include <queue>

using namespace std;

struct loc{
  int x;
  int y;
}typedef loc;

int dp[101][101];

queue<loc> q;
int N;
loc temp;

void find_before_loc(loc c_loc);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  cin >> N;

  for(int i =0; i<N; i++){
    for(int j =0; j<N; j++){
      cin >> dp[i][j];
    }
  }

  for(int i = 1; i<N; i++){
    if(dp[N-1][N-1-i] - i == 0){
      temp.x = N-1;
      temp.y = N-1-i;
      q.push(temp);
      //cout << temp.x << " " <<temp.y <<endl;
    }  
    if (dp[N-1-i][N-1] - i ==0){
      temp.x = N-1-i;
      temp.y = N-1;
      q.push(temp);
      //cout << temp.x << " " <<temp.y <<endl;
    }
  }

  long long ans = 0;

  while(!q.empty()){
    temp = q.front();
    q.pop();

    if(temp.x == 0 && temp.y == 0){
      ans++;
      continue;
    }

    find_before_loc(temp);
  }

  cout <<ans;
  return 0;

}

void find_before_loc(loc c_loc){

  for(int i = 1; i<=c_loc.y; i++){
    if(dp[c_loc.x][c_loc.y-i] - i == 0){
      temp.x = c_loc.x;
      temp.y = c_loc.y-i;
      q.push(temp);
      //cout << temp.x << " " <<temp.y <<endl;
    }  
  }

  for(int i = 1; i<=c_loc.x; i++){
    if (dp[c_loc.x-i][c_loc.y] - i ==0){
      temp.x = c_loc.x-i;
      temp.y = c_loc.y;
      q.push(temp);
      //cout << temp.x << " " <<temp.y <<endl;
    }
  }
}
