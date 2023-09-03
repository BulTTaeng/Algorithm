#include <iostream>
#include <vector>

using namespace std;

vector<int> n_sdr;
vector<int> sdr;

int input[2001];

void binary(int num);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int n;
  cin>>n;

  for(int i =0; i<n; i++){
    cin >> input[i];
  }

  sdr.push_back(input[0]);
  n_sdr.push_back(1);

  for(int i =1; i<n; i++){
    if(input[i] < sdr.back()){
      sdr.push_back(input[i]);
      n_sdr.push_back(sdr.size());
    }
    else{
      binary(input[i]);
    }
  }


  cout << n - n_sdr.back();
  return 0;

}

void binary(int num){
  int start =0;
  int end = sdr.size() -1;
  int mid , loc =909999;

  while(start  <= end){
    mid = (start + end) /2;

    if(num >= sdr[mid]){
      end = mid-1;
      if(loc > mid){
        loc = mid;
      }
    }
    else{
      start = mid+1;
    }
  }

  sdr[loc] = num;
  n_sdr.push_back(sdr.size());
}
