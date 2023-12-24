#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

double dp[10001];
vector<double> num;

double find_max(double a , double b);

int main() {

  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  
  int N;
  double input;

  cin >> N;

  for (int i =0; i<N; i++){
    cin >> input;
    num.push_back(input);
  }

  double max = 0;
  dp[0] = num[0];

  for(int i =1; i<N; i++){
    dp[i] = find_max(num[i] , dp[i-1] * num[i]);
    if(max < dp[i]){
      max = dp[i];
    }
  }
  cout << fixed;
	cout.precision(3);

  max = round(max * 1000) /1000;
  cout << max;
  cout.unsetf(ios::fixed);
  return 0;
}

double find_max(double a , double b){
  if(a>b) return a;
  else return b;
}
