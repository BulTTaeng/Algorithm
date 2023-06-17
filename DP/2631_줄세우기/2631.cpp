#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;

int inp[202];

void binary(int num);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin >> n;

  for(int i =0; i<n; i++){
    cin >> inp[i];
  }

  dp.push_back(inp[0]);

  for(int i =1; i<n; i++){
    if(dp.back() < inp[i]){
      dp.push_back(inp[i]);
    }
    else{
      binary(inp[i]);
    }
  }

  cout << n- dp.size();
  return 0;
}

void binary(int num){
  int start = 0;
  int end = dp.size() - 1;

  int mid , loc = 100009;

  while(start <= end){
    mid = (start + end)/2;

    if(num <= dp[mid] ){
      end = mid-1;
      
      if(loc > mid){
        loc = mid;
      }
    }
    else{
      start = mid+1;
    }
  }
  dp[loc] = num;
}
