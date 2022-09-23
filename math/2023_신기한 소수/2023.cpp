#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int> ans;
int dx[] = {1, 3, 7, 9};
long long nx;

bool is_prime(int num);
void dfs(int num, int size);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  dfs(2, 1);
  dfs(3, 1);
  dfs(5, 1);
  dfs(7, 1);

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << "\n";
  }
}

bool is_prime(int num) {

  bool re = true;

  for (int i = 2; i <= sqrt(num) + 0.1; i++) {
    if (num % i == 0) {
      re = false;
      break;
    }
  }

  return re;
}

void dfs(int num, int size) {

  if (is_prime(num)) {
    if (size == N) {
      ans.push_back(num);
    } else {
      for (int i = 0; i < 4; i++) {
        dfs(num * 10 + dx[i], size + 1);
      }
    }
  } else {
    return;
  }
}
