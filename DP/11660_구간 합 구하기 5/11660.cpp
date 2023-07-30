#include <iostream>
#include <algorithm>

using namespace std;

int dp[1025][1025];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N , M , input;

  cin >> N >> M;

  for(int i =1; i <=N ; i++){
    for(int j =1; j<=N ; j++){
      cin >> input;
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + input;
    }
  }

  /*for(int i =1; i <=N ; i++){
    for(int j =1; j<=N ; j++){
      cout << dp[i][j] << " ";
    }
    cout<<endl;
  }*/

  int ans, x1 ,x2 ,y1, y2;

  for(int i =1; i<=M; i++){
    cin >> x1 >> x2 >> y1 >> y2;
    cout << dp[y1][y2] - dp[y1][x2-1]-dp[x1-1][y2] + dp[x1-1][x2-1] << "\n";
    //cout << ans<<endl;
  }

  return 0;
}
