#include <iostream>

using namespace std;

string n1 , n2;

int main() {

  cin >> n1 >> n2;

  int l1 = n1.length();
  int l2 = n2.length();

  int ans = 0;

  if(l2 == l1){
    for(int i =0 ; i<l1; i++){
      if(n1[i] == n2[i]){
        if(n1[i] == '8'){
          ans++;
        }
      }
      else{
        break;
      }
    }
  }
  
  cout << ans;
  return 0;
  
}
