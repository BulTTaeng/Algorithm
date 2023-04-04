#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int N, c, s;

struct ball {
  int c;
  int s;
  int idx;
} typedef ball;

struct compare {
  bool operator()(ball &b1, ball &b2) {
    if (b1.s == b2.s)
      return b1.c < b2.c;
    return b1.s < b2.s;
  }
};

vector<ball> v;
int sum[200001];
int ans[200001];

void solve() {

  int allsum = 0;
  ball curr;
  int beforesize = 0;
  int beforecount = 0;
  int beforecolor = 0;
  int ccount = 0;

  for (int i = 0; i < v.size(); i++) {
    curr = v[i];

    if (beforesize == curr.s) { //같은 사이즈
      //같은 색, 같은 사이즈 빼기
      ans[curr.idx] = allsum - sum[curr.c] - (beforesize * beforecount);
      
      if (beforecolor == curr.c) { //같은 색, 같은 사이즈
        //위 빼기 연산에서 중복으로 빼진 값 다시 더하기
        ans[curr.idx] += (ccount * curr.s);
        ccount++;
      } 
      else { // 같은 색 count 초기화
        ccount = 1;
      }
      beforecount++;
    } 
    else { //다른 사이즈
      ans[curr.idx] = allsum - sum[curr.c];
      beforecount = 1;
      ccount =1;
    }
    
    allsum += curr.s;
    sum[curr.c] += curr.s;

    beforesize = curr.s;
    beforecolor = curr.c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  ball b;

  for (int i = 0; i < N; i++) {
    cin >> c >> s;
    b.c = c;
    b.s = s;
    b.idx = i;
    v.push_back(b);
  }

  sort(v.begin(), v.end(), compare());
  memset(sum, 0, sizeof(sum));

  solve();

  for (int i = 0; i < N; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
