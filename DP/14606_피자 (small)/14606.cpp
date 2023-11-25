#include <iostream>

using namespace std;

int dp[12];

int main() {
  
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int N;
  cin >> N;

  dp[1] = 0;

  int sep1 , sep2;

  for(int i =2; i<=N; i++){
    int temp;

    sep1 = i/2;
    sep2 = i - i/2;

    temp = sep1 * sep2 ;
    temp = temp + dp[sep1] + dp[sep2];
    dp[i] = temp;
  }

  cout <<dp[N];
  return 0;
}
