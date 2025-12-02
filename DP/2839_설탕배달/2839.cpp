#include <iostream>

using namespace std;

int dp[5001] = {0,};
int possible =0;

int find_sugarbag(int g);

int main() {
  int input =0;
  cin >> input;

  int ans = find_sugarbag(input);
  cout << ans;
}

int find_sugarbag(int g){

  if(g <3 || g ==4){
    dp[g] = -1;
    possible =1;
    return -1;
  }
  else if(g == 3){
    dp[3] = 1;
    g =0;
    return 1;
  }
  else if(g == 5){
    dp[5] =1;
    g = 0;
    return 1;
  }
  else if (dp[g] != 0){
    return dp[g];
  }
  else{
    if(g % 5 == 0){
      dp[g] = (g / 5);
      return dp[g];
    }
    else{
      dp[g] = find_sugarbag(g-3) + 1;
    }
  }

  if(possible == 1){
    return -1;
  }
  else{
    return dp[g];
  }

}
