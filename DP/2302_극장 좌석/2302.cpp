#include <iostream>
#include <queue>

using namespace std;

long long dp[42];
int input[42];

queue<long long> q;

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N , M;

  cin >> N >>M;

  for(int i =1; i<=M; i++){
    cin >> input[i];
  }

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for(int i = 3; i<=40; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }

  if(M == 0){
    cout <<dp[N];
    return 0;
  }
  if(M == N){
    cout <<1;
    return 0;
  }

  long long ans =1;
  int temp =0;

  q.push(input[1] -1 );

  for(int i =2;  i<=M; i++){
    temp = input[i] - input[i-1] -1;
    q.push(temp);
  }

  q.push(N-input[M]);

  while(!q.empty()){
    temp = q.front();
    q.pop();
    ans = ans * dp[temp];  
  }
  cout <<ans;
  return 0;
}
