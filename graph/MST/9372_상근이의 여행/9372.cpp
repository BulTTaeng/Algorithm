#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<int> q;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int t , n , m, t1 ,t2;
  cin >> t;

  for(int i =0; i<t; i++){

    cin >> n >> m;

    for(int j =0; j<m; j++){
      cin >>t1 >> t2;
    }
    cout << n-1 <<"\n";
  }

  return 0;
}
