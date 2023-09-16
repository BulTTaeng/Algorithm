#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[102][102];

int recur(int a , int b);

int main() {

  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int a ,b;

  cin >> a >> b;

  memset(dp, -1 , sizeof(dp));

  int ans = recur(a,b);

  if(ans == 1){
    cout << "A";
  }
  else{
    cout <<"B";
  }

  return 0;
}

int recur(int a, int b){
  if(a == 0 || b == 0){
    return 0;
  }

  else if(a == 1 && b == 1){
    return 2;
  }

  if(dp[a][b] != -1){
    return dp[a][b];
  }

  dp[a][b] = 0;

  for (int i = 1; i < b; i++) {
			int temp = recur(i, b - i);

			if (temp == 0 || temp == 2) {
				return dp[a][b] = 1;
			}
	}

  for (int i = 1; i < a; i++) {
			int temp = recur(i, a - i);

			if (temp == 0 || temp == 2) {
				return dp[a][b] = 1;
			}
		}

		return dp[a][b];
  

}
