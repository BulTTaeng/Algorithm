#include <iostream>
#include <cstring>

using namespace std;

int N, M , K;
long long dp[101][101]; //a개수 z개수
long long maxnum = 1000000001;

void filldp(){
  dp[0][0] = 0;
  for(int i =1; i<=N; i++){
    dp[i][0] = 1;
  }

  for(int i = 1; i<=M; i++){
    dp[0][i] = 1;
  }

  for(int i =1; i<=N; i++){
    for(int j =1; j<=M; j++){
      dp[i][j] = min(dp[i-1][j] + dp[i][j-1] , maxnum);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> N >> M >> K;

  memset(dp , 0 , sizeof(dp));

  filldp();

  if(dp[N][M] < K){
    cout << -1;
    return 0;
  }

  int n = N;
  int m = M;
  int cn, cm;
  
  for(int i= 0; i<N+M; i++){
    cn = dp[n-1][m]; //만약 현재 위치에 a를 넣는다면, 나올 수 있는 최대 순번의 수
    //ex), N=2 , M=2일 경우 4자리 수에서 맨앞에 a를 고정한다면 aazz, azaz, azza 
    //(앞에서 3번째 까지의 수들) 

    if(n == 0){
      cout << 'z';
    }
    else if(m == 0){
      cout << 'a';
    }
    else{
      if(cn >= K){ //현재 a를 하나더 고정하는 가짓수가 k보다 크면
        //현재 10억보다 큰 값은 모두 10억1로 해놨음
        // 따라서 앞에서 10억까지인 K의 범위 안에 들려면 차피 현재 값은 무조건 a여야 함.
        //(현재 z가 나오려면 10억 이후의 값이여야 함)
        cout << 'a';
        n--;
      }
      else{ //이제 a가 나올 수 없음. 따라서 z가 나오는데, a가 나올 수 있는 가짓수를 빼야함
        //a가 나올 수 있는 가짓수를 빼는 이유는, 앞에서부터 K번째 값을 찾는 건데
        //현재 위치에 a가 나오는 수는 현재 수보다 모두 앞에 있는 문자열을 빼줘야함
        //즉, 현재 위치에 z가 나오는 수 중에서 K-cn번째 값을 찾아야 함.
        K -= cn;
        cout <<'z';
        m--;
      }
    }
  }

  return 0;
}
