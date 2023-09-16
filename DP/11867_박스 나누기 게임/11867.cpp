#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int a ,b;

  cin >> a >> b;
  
  if(a %2 == 0 || b %2 == 0){
    cout << "A";
  }
  else{
    cout << "B";
  }

  return 0;
}
