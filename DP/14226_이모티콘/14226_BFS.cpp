#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct info{
  int time;
  int num;
  int clip;
} typedef info;

bool visit[1002][1002];

queue<info> q;
int n;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin>> n;

  memset(visit, false ,sizeof(visit));

  info temp , newone;
  temp.time = 0;
  temp.num = 1;
  temp.clip = 0;
  
  q.push(temp);
  visit[1][0] = true;
  int ans;

  while(!q.empty()){
    temp = q.front();
    q.pop();

    if(temp.num == n){
      ans = temp.time;
      break;
    }


      if(visit[temp.num][temp.num] == false){
        newone.time = temp.time +1;
        newone.clip = temp.num;
        newone.num = temp.num;
        q.push(newone);
        visit[temp.num][temp.num] = true;
      }
    
      if((temp.num + temp.clip) < 1001 && temp.clip > 0){
        if(visit[temp.num + temp.clip][temp.clip] == false){
          newone.time = temp.time +1;
          newone.clip = temp.clip;
          newone.num = temp.num + temp.clip;
          q.push(newone);
          visit[temp.num + temp.clip][temp.clip] = true;
        }
      }

      if(visit[temp.num-1][temp.clip] == false && temp.num > 0){
        newone.time = temp.time +1;
        newone.clip = temp.clip;
        newone.num = temp.num -1;
        q.push(newone);
        visit[temp.num -1][temp.clip] = true;
      }

  }

  cout << ans;
  return 0;
}
