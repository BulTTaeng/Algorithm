#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> inp;
long long sum = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;
  int temp;
  for(int i =0; i<N; i++){
    cin >> temp;
    inp.push_back(temp);
  }

  sort(inp.begin() , inp.end());

  sum =1;

  for(int i =0; i<N; i++){
    if(sum < inp[i]){
      break;
    }
    else{
      sum += inp[i];
    }
  }

  cout << sum;

  return 0;
}
