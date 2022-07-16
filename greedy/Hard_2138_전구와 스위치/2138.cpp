#include <iostream>
#include <cstring>

using namespace std;

int N;
bool start[100001];
bool target[100001];
bool t[100001];

#define MAX 987654321

int ans = MAX;

int solve(bool p);
void press(int loc);
bool same();

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  
  cin >> N;

  char c;

  for(int i =0; i<N; i++){
    cin >> c;
    if(c == '0'){
      start[i] = false;
    }
    else{
      start[i] = true;
    }
  }

  for(int i =0; i<N; i++){
    cin >> c;
    if(c == '0'){
      target[i] = false;
    }
    else{
      target[i] = true;
    }
  }

  ans = min(solve(true) , solve(false));

  if(ans != MAX){
    cout << ans;
  }
  else{
    cout << -1;
  }
  
  return 0;  
}

int solve(bool p){

  int temp = 0;

  for(int i =0; i<N;i++){
    t[i] = start[i];
  }
  

  if(p){
    t[0] = !t[0];
    t[1] = !t[1];
    temp++;
  }
  
  for(int i =1; i<N; i++){
    if(t[i-1] != target[i-1]){
      press(i);
      temp++;
    }
  }

  if(same()){
    return temp;
  }
  else{
    return MAX;
  }
  
}

void press(int loc){
  
  for(int i =loc-1; i<=loc+1; i++){
    if(i>=0 && i<N){
      t[i] = !t[i];
    }
  }
}

bool same(){
  for(int i =0; i<N; i++){
    if(t[i] != target[i]){
      return false;
    }
  }

  return true;
}
