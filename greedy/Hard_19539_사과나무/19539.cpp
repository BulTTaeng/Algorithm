#include <iostream>
#include <cstring>

using namespace std;

int N;
int inp[100001];
int sum = 0;
int sum2 = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;

  for(int i =0; i<N; i++){
    cin >> inp[i];
    sum += inp[i];
    sum2 += inp[i]/2;
  }

  int time = sum/3;
  int left = sum%3;

  if(left != 0){
    cout << "NO";
  }
  else{
    if(sum2 >= time){
      cout << "YES";
    }else{
      cout << "NO";
    }
  }
  

  return 0;
}
