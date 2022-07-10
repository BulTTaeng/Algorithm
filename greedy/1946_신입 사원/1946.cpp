#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T , N , f,s;
int ans = 0;
int mini = 100001;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;

  while(T--){
    vector<pair<int , int>> v;
    mini = 100001;
    ans = 0;

    cin >> N;

    for(int i =0; i<N; i++){
      cin >> f >> s;
      v.push_back({f,s});
    }

    sort(v.begin() , v.end());

    for(int i =0; i<N; i++){
      if(mini > v[i].second){
        ans++;
      }

      mini = min(mini , v[i].second);
    }

    cout << ans << "\n";
  }

  return 0;
}
