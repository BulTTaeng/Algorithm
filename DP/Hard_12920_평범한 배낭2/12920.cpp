#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> stuff;

int dp[10002] = {
    0,
};

int N, M;

int main() {
  cin >> N >> M;
  int v; // 무게
  int c; // 만족도
  int k; // 개수

  int temp, currWeight, currHappy;

  for (int i = 1; i <= N; i++) {
    cin >> v >> c >> k;

    for (int j = k; j > 0; j = j >> 1) {
      temp = j - (j >> 1);
      stuff.push_back({v * temp, c * temp});
    }
  }

  dp[0] = 0;

  for (int i = 0; i < stuff.size(); i++) {
    currWeight = stuff[i].first;
    currHappy = stuff[i].second;

    for (int j = M; j >= currWeight; j--) {
      dp[j] = max(dp[j], dp[j - currWeight] + currHappy);
    }
  }

  cout << dp[M];

  return 0;
}
