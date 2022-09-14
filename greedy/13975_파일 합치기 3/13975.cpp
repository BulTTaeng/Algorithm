#include <iostream>
#include <queue>

using namespace std;

int T, N;
long long ans = 0;
priority_queue<long long, vector<long long>, greater<>> pq;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> T;
  int temp;

  while (T--) {
    cin >> N;

    for (int i = 0; i < N; i++) {
      cin >> temp;
      pq.push(temp);
    }

    long long n1 = 0, n2 = 0;
    ans = 0;

    while (pq.size() != 1) {
      n1 = pq.top();
      pq.pop();

      n2 = pq.top();
      pq.pop();

      ans += n1;
      ans += n2;
      pq.push(n1 + n2);
    }

    pq.pop();

    cout << ans << "\n";
  }

  return 0;
}
