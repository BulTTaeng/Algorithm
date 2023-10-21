#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
vector<int> dp_size;

int input[1002];

void binary(int num);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for(int i =0; i<n;i++){
    cin >> input[i];
  }

  dp.push_back(input[0]);
  dp_size.push_back(dp.size());

  for(int i =1; i<n; i++){
    if(input[i] > dp.back() ){
      dp.push_back(input[i]);
      dp_size.push_back(dp.size());
    }
    else{
      binary(input[i]);
    }
  }

  cout << dp_size.back();
  return 0;
}

void binary(int num){
  int start = 0;
  int end = dp.size()-1;
  int mid , loc = 1003;

  while(start <= end){
    mid = (start + end)/2;

    if(num <= dp[mid]){
      end = mid-1;
      
      if(loc > mid){
        loc = mid;
      }
    }
    else{
      start = mid +1;
    }

  }
  dp[loc] = num;
  dp_size.push_back(dp.size());
}
