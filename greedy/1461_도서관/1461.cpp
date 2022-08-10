#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
priority_queue<int, vector<int>> p;
priority_queue<int, vector<int>, greater<>> m;
long long ans = 0;

void addplus();
void addminus();

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);

  cin >> N >> M;

  int temp;

  for (int i = 0; i < N; i++) {
    cin >> temp;

    if (temp < 0) {
      m.push(temp);
    } else {
      p.push(temp);
    }
  }

  if (p.empty()) {
    addminus();
  } else if (m.empty()) {
    addplus();
  } else if (abs(m.top()) > p.top()) {
    addminus();
  } else {
    addplus();
  }

  while (!p.empty()) {

    ans += p.top() * 2;

    for (int i = 0; i < M; i++) {
      if (!p.empty()) {
        p.pop();
      } else {
        break;
      }
    }
  }

  while (!m.empty()) {

    ans += abs(m.top()) * 2;

    for (int i = 0; i < M; i++) {
      if (!m.empty()) {
        m.pop();
      } else {
        break;
      }
    }
  }

  cout << ans;
  return 0;
}

void addplus() {
  ans += p.top();
  for (int i = 0; i < M; i++) {
    if (!p.empty()) {
      p.pop();
    }
  }
}

void addminus() {
  ans += abs(m.top());

  for (int i = 0; i < M; i++) {
    if (!m.empty()) {
      m.pop();
    }
  }
}
