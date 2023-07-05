#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

queue<int> start;

string target;
string temp;
vector<string> eng[27]; 
bool visit[102];

int main() {
  cin >> target;

  int n ;
  cin >> n;

  for(int i =0; i<n; i++){
    cin >> temp;
    eng[int(temp[0] - 'a')].push_back(temp);
  }
  
  start.push(0);
  int s;

  bool possible = true;
  int ans = 0;

  memset(visit, false , sizeof(visit));

  visit[0] = true;

  while(!start.empty()){
    s = start.front();
    start.pop();

    if(s == target.size()){
      ans = 1;
      break;
    }

    for(int i =0; i<eng[target[s] -'a'].size(); i++ ){
      possible = true;

      for(int j =0; j<eng[target[s] - 'a'][i].length(); j++){
        if(eng[target[s] - 'a'][i][j] == target[s+j]){
          //cout << " ok ";
          continue;
        }
        else{
          possible = false;
          break;
        }
      }

      if(possible == true){
        if(visit[s +eng[target[s] - 'a'][i].length()] == false){
          start.push(s+eng[target[s] - 'a'][i].length() );
          visit[s + eng[target[s] - 'a'][i].length()] = true;
        }
      }

    }
    
  }
  cout << ans;
  return 0;

}
