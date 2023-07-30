#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<int> v_len;

int inp[1002];

void binary(int num);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n ;
  cin>> n;

  for(int i =0;i<n; i++){
    cin >> inp[i];
  }

  v.push_back(inp[0]);
  v_len.push_back(1);

  for(int i =1; i<n; i++){
    if(inp[i] > v.back()){
      v.push_back(inp[i]);
      v_len.push_back(v.size());
    }
    else{
      binary(inp[i]);
    }
  }

  cout << v_len.back();
  return 0;

}

void binary(int num){
  int start = 0;
  int end = v.size()-1;
  int mid , loc = 1002;

  while(start<=end){
    mid = (start + end )/2;

    if(v[mid] >= num){
      end = mid-1;
      if(loc > mid){
        loc = mid;
      }

    }
    else{
      start = mid+1;
    }
  }

  v[loc] = num;
  v_len.push_back(v.size());
}
