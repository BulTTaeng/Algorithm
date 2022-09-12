#include <algorithm>
#include <iostream>

using namespace std;

int N;
string inp;
int minR = 0, minB = 0;
int minusR = 0, minusB = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;
  cin >> inp;

  char p = inp[0];
  int temp = 1;

  for (int i = 1; i < N; i++) {
    if (p != inp[i]) {
      if (p == 'R') {
        minR += temp;
      } else if (p == 'B') {
        minB += temp;
      }
      temp = 1;
    } else {
      temp++;
    }

    p = inp[i];
  }

  if (temp == N) {
    cout << 0;
    return 0;
  }

  if (p == 'R') {
    minR += temp;
  } else {
    minB += temp;
  }

  temp = 1;

  for (int i = 0; i < N - 1; i++) {
    if (inp[i] == inp[i + 1]) {
      temp++;
    } else {
      break;
    }
  }

  if (inp[0] == 'R') {
    minusR = temp;
  } else {
    minusB = temp;
  }

  temp = 1;

  for (int i = N - 1; i > 0; i--) {
    if (inp[i] == inp[i - 1]) {
      temp++;
    } else {
      break;
    }
  }

  if (inp[N - 1] == 'R') {
    minusR = max(temp, minusR);
  } else {
    minusB = max(temp, minusB);
  }

  cout << min(minB - minusB, minR - minusR);
  return 0;
}
