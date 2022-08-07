#include <iostream>
#include <vector>

using namespace std;

int N;
int dice[7];
int mini[4];
long long ans = 0;
long long mindice = 55;
int maxdice = -1;
int minloc =-1;
int s,t;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;
  
  for(int i=1; i<=6; i++){
    cin >> dice[i];

    if(mindice > dice[i]){
      mindice = dice[i];
      minloc = i;
    }
    maxdice = max(maxdice , dice[i]);
  }

  if(N ==1){
    for(int i =1; i<=6 ; i++){
      ans += dice[i];
    }
    ans -= maxdice;
    cout << ans;
    return 0;
  }

  for(int i =1; i<=3; i++){
    mini[i] = min(dice[i] , dice[7-i]);
  }
  //마주보고 있는 최소값들

  ans = mindice*(N-2) * (N-2)*5; //중앙, 5면
  ans += mindice *(N-2)*4; // 4면의 바닥과 붙은 부분

  if(minloc == 1 || minloc == 6){
    s = min(mini[2] , mini[3]);
    t = max(mini[2] , mini[3]);
  }
  else if(minloc == 2 || minloc == 5){
    s = min(mini[1] , mini[3]);
    t = max(mini[1] , mini[3]);
  }
  else{
    s = min(mini[1] , mini[2]);
    t = max(mini[1] , mini[2]);
  }
  
  ans += (mindice+s) *(N-1) *4; //4개 기둥

  ans += (mindice+s) * (N-2) *4; // 윗면의 중간 블럭들

  ans += (mindice + s + t) * 4; // 윗면의 모서리들  
  
  cout << ans;
  return 0;
}
