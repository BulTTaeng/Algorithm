#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

struct loc_jump{
  int loc;
  int jump;
  int ans;
} typedef loc_jump;

queue<loc_jump> q;
loc_jump input[1001];
bool visit[1001];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i =0; i<n; i++){
    cin >> input[i].jump;
    input[i].loc = i;
    input[1].ans = 0;
  }

  memset(visit, false, sizeof(visit));

  q.push(input[0]);

  loc_jump curr;
  loc_jump temp;
  
  int ans =-1;

  while(!q.empty()){

    curr = q.front();
    q.pop();

    visit[curr.loc] =true;

    if(curr.loc == n-1){
      ans = curr.ans;
      break;
    }

    for(int i =1 ; i<=curr.jump; i++){
      
      if(visit[curr.loc + i] == true){
        continue;
      }

      else{
        visit[curr.loc +i] =true;
        temp = input[curr.loc + i];
        temp.ans = curr.ans +1;
        q.push(temp);
      }
    }

  }

  cout <<ans;
  return 0;


}
