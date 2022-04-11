#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int N , W , L;
int inp[1001];
int loc[1001];

queue<int> q;

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> W >> L;

  for(int i =0; i<N; i++){
      cin >> inp[i];
      q.push(inp[i]);
  }

  int time = 0;
  int weight = L;
  int s = 0;
  int e = 0;

  memset(loc , 0 ,sizeof(loc));

  while(true){
      time++;

      for(int i =s; i<e; i++){
          loc[i]++;

          if(loc[i] > W){
              s = i+1;
              weight += inp[i];
          }
      }

      if(!q.empty()){
        if(weight >= q.front()){
            weight -= inp[e];
            loc[e]++;
            e++;
            q.pop();
        }
      }

      if(s == N){
          break;
      }

  }

  cout << time;
  return 0;

}
