#include <iostream>

using namespace std;

int t[1500002];
int p[1500002];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin>> n;

  for(int i=1 ; i<=n; i++){
    cin >> t[i] >> p[i];
  }

  p[n+1] = 0;
  int ans = 0;
  for(int i = n; i>0; i--){
    
    if(i + t[i] > n+1){ //impossible
      p[i] = p[i+1];
    }

    else{
      p[i] = max(p[i+1] , p[i] + p[i+t[i]] );
    }
    if(ans < p[i]){
      ans = p[i];
    }
  }

  cout << ans;
  return 0;
}
