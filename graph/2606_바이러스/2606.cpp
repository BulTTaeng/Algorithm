#include <iostream>

using namespace std;

int root[102];

int _find(int x);
void _union(int x, int y);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n , edge, x, y;
  cin >>n;
  cin >> edge;

  for(int i = 1; i<=n; i++){
    root[i] = i;
  }

  for(int i =1 ; i<=edge; i++){
    cin>> x >> y;

    if(x < y){
      _union(x, y);
    }
    else{
      _union(y,x);
    }

  }

  int count = 0;

  for(int i =2; i<=n; i++){
    if (_find(i) == _find(1)) count++;
  }

  cout << count;
  return 0;
}

int _find(int x){
  if(root[x] == x){
    return x;
  }
  else{
    return root[x] = _find(root[x]);
  }
}

void _union(int x , int y){
  if(x == y ) return;
  
  x = _find(x);
  y = _find(y);

  root[y] = x;
}
