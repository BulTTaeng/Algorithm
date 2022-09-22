#include <iostream>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

int D , N;
vector<int> pizza;
vector<int> oven;
bool block[300001];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> D >> N;
  
  int temp;
  
  for(int i =0; i<D; i++){
    cin >> temp;
    if(i!=0 && oven[i-1] < temp){
      oven.push_back(oven[i-1]);
    }
    else{
      oven.push_back(temp);
    }
  }

  for(int i =0; i<N; i++){
    cin >> temp;
    pizza.push_back(temp);
  }

  int num = 0;
  int ans = 0;

  for(int i =D-1; i>=0 ; i--){
    if(num == N){
      break;
    }
    if(oven[i] >= pizza[num]){
      num++;
      ans = i+1;
    }
  }
  
  if(num == N){
    cout << ans;
  }
  else{
    cout << 0;
  }

  return 0;
  
}
