#include <iostream>

using namespace std;

long long dp_x[32];
long long dp_y[32];

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int D , K;
  cin >> D >> K;

  dp_x[0]= 0;
  dp_x[1] = 1;
  dp_y[0] = 0;
  dp_y[1] = 0;
  dp_y[2] = 1;
  dp_x[3] = 1;
  dp_y[3] = 1;

  for(int i =4; i<=D; i++){
    dp_y[i] = dp_y[i-1] + dp_y[i-2];
    dp_x[i] = dp_x[i-1] + dp_x[i-2]; 
  }

  int first =0 , second = 0;

  for(int i =1; i<=K; i++){
       for(int j = 1; j<=K; j++){
         if(dp_x[D] * i + dp_y[D] * j == K){
           first = i;
           second = j;
           break;
         }
       }
       if(first != 0 ){
         break;
       }
  }

  //cout << dp_x[D] << " "<<dp_y[D];

  cout << first <<endl << second;
  return 0;
  
}
