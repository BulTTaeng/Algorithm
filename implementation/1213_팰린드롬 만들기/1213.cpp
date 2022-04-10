#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string str;
int c[27];

int main(){
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> str;

  for(int i =0; i<str.length(); i++){
      c[(int)(str[i] - 'A')]++;
  }

  int odd = 0;
  int odd_loc = -1;

  for(int i =0; i<26; i++){
      if(c[i] % 2 == 1){
          odd++;
          odd_loc = i;
          if(odd > 1){
              cout << "I'm Sorry Hansoo";
              return 0;
          }
      }
  }

  string ans = "";
  string tans = "";

  for(int i =0; i<26; i++){
      for(int j =0; j<c[i]/2; j++){
          tans += (char)(i+'A');
      }
  }

  ans += tans;

  if(odd == 1){
      ans += (char)(odd_loc+'A');
  }

  reverse(tans.begin() , tans.end());

  ans += tans;
  
  cout << ans;
  return 0;
}
