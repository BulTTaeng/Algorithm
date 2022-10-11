#include <cmath>
#include <iostream>

using namespace std;

int N, M;
int matrix[1002][1002];
char temp;
int dp[1002][1002];
int ans = 0;

void solve();

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> temp;
      matrix[i][j] = temp - '0';
    }
  }

  solve();

  cout << ans * ans;
  return 0;
}

void solve() {

  for (int i = 0; i < N; i++) {
    dp[i][0] = matrix[i][0];
    ans = max(ans, dp[i][0]);
  }

  for (int j = 0; j < M; j++) {
    dp[0][j] = matrix[0][j];
    ans = max(ans, dp[0][j]);
  }

  for (int i = 1; i < N; i++) {
    for (int j = 1; j < M; j++) {
      if (matrix[i][j] == 1) {
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        ans = max(ans, dp[i][j]);
      }
    }
  }
}
