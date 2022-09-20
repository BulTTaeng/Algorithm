#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N , temp;
vector<int> inp;
int dp[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;

  for(int i =0; i<N; i++){
    cin >> temp;
    inp.push_back(temp);
  }

  memset(dp , 0, sizeof(dp));


  for(int i =0; i<N; i++){
    
    dp[inp[i]] = dp[inp[i]-1]+1;
  
  }  

  int maxi = 0;

  for(int i =1; i<=N; i++){
    maxi = max(dp[i] , maxi);
  }

  cout << N-maxi;

  return 0;
}
