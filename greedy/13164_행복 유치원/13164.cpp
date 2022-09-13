#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> inp;
vector<int> dis;
int ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> K;
  int temp;

  for(int i =0; i<N; i++){
    cin >> temp;
    inp.push_back(temp);
  }

  for(int i =0; i<N-1; i++){
    temp = inp[i+1] - inp[i];
    dis.push_back(temp);
  }

  sort(dis.begin()  ,  dis.end());

  for(int i =0; i<N-K; i++){
    ans += dis[i];
  }

  cout << ans;
  return 0;
}
