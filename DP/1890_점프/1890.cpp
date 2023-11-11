#include <iostream>

using namespace std;

int dp[101][101];

long long j_case[101][101] = {0, };

int N;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  cin >> N;

  for(int i =0; i<N; i++){
    for(int j =0; j<N; j++){
      cin >> dp[i][j];
    }
  }

  j_case[0][0] = 1;

  for(int i =0; i<N; i++){

    for(int j = 0; j<N; j++){
      
      if(j_case[i][j] > 0 && dp[i][j] != 0){

        if( i+dp[i][j] < N){
          j_case[ i+dp[i][j] ][j] += j_case[i][j];
        }

        if( j+dp[i][j] < N){
          j_case[i][ j+ dp[i][j] ] += j_case[i][j];
        }
      }

    }

  }

  cout <<j_case[N-1][N-1];
  return 0;

}
