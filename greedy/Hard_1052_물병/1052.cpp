#include <iostream>

using namespace std;

int N , K;
int ans = -1;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  
  cin >> N >> K;

  int count = 0;
  int temp ;
  int n = N;
  
  while(true){
    count = 0;
    temp = n;
    while(temp){
      if(temp %2 == 0){
        temp /=2;
      }  
      else{
        temp /=2;
        count++;
      }
    }

    if(count <= K){
      ans = n-N;
      break;
    }
    
    n++;
  }

  cout << ans;
  return 0;
}
