#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, T;
int cake[32];
int target[32];
vector<int> ans; 

void moveBottom(int num, int b);
void moveCake(int num);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> N;
    ans.clear();

    for (int i = 1; i <=N; i++) {
      cin >> cake[i];
      target[i] = i;
    }

    for(int i =N; i>1; i--){
      moveBottom(cake[i] , i);
    }

    cout << ans.size() << " ";
    for(int i =ans.size()-1; i>=0; i--){
      cout << ans[i] << " ";
    }
    cout << "\n";
  }

  return 0;
}


void moveBottom(int num , int b){
  int loc =-1;
  
  for(int i =1; i<=b; i++){
    if(target[i] == num){
      loc = i;
      break;
    }  
  }


  if(loc == b){
    return;
  }
  if(loc >1){
    ans.push_back(loc);
    moveCake(loc);
  }
  ans.push_back(b);
  moveCake(b);
}


void moveCake(int num ){

  int temp = num;
  
  for(int i =1; i<=num/2; i++){
    swap(target[i] , target[temp]);
    temp--;
  }
}
