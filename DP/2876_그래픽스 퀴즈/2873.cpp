#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001][6] = {0, };

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int N;
  int max= 0;
  int grade =6;

  cin >> N;

  int first, second;

  for(int i =0; i<N; i++){
    cin >> first >> second;
    
    dp[i][first] = dp[i-1][first] +1;

    if (max == dp[i][first] && grade > first){
        max = dp[i][first];
        grade = first;
    }

    if(max < dp[i][first]){
        max = dp[i][first];
        grade = first;
    }

    if(first != second){
      dp[i][second] = dp[i-1][second] +1;

      if (max == dp[i][second] && grade > second){
        max = dp[i][second];
        grade = second;
      }

      if(max < dp[i][second]){
        max = dp[i][second];
        grade = second;
      }
    }

  }
  
  cout << max << " " << grade;
  return 0;
}
