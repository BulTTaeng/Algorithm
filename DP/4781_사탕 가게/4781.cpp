#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[100001];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  double td;
  int t;
  

  while(true){

    int n ; 
    double m;

    cin >> n >> m;
    
    if(n == 0 && abs(m - 0.00) < 0.005){
      break;
    }

    memset(dp,0,sizeof(dp));

    int m1 = int(m*100 + 0.5);

    vector<int> c;
    vector<int> p;

    for(int i =0; i<n; i++){
      cin >> t >> td;
      c.push_back(t);
      p.push_back( int(td *100 + 0.5) );
    }

    for(int i =0; i<n; i++){
      for(int j = p[i]; j<=m1; j++){
        dp[j] = max(dp[j] , dp[j-p[i]] + c[i]);
      }
    }

    cout << dp[m1] << "\n";
  }


}
