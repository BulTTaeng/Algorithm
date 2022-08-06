#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
int ans = 0;
vector<int> v;
int sum[100001];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N;

  int temp;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    v.push_back(temp);
  }

  int middle = 0;
  int maxi = -1;
  
  for (int i = 1; i < N - 1; i++) {
    middle += v[i];
    maxi = max(maxi, v[i]);
  }
  
  ans = max(ans, maxi + middle);

  memset(sum , 0 , sizeof(sum));

  sum[0] = v[0];

  for(int i =1; i<N; i++){
    sum[i] = v[i] + sum[i-1];
  }
  
  int r = 1;
  for(int i= 1; i<=N-3; i++){
    if(v[i]-v[i+1] > v[i+1]){
      r= i+1;
    }
    else{
      break;
    }
  }  

  ans = max(ans , (sum[N-1]- v[0]) + (sum[N-1] - sum[r] - v[r]));

  
  for(int i = N-2; i>=1; i--){
    ans = max(ans , (sum[N-2] - v[i]) + (sum[i] -v[i]));
  }

  
  cout << ans;

  return 0;
}
