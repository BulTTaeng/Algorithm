#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N , M , L;
vector<int> loc;

int ans = 10001;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  cin >> N >> M >> L;
  int temp;

  for(int i =0; i<N; i++){
    cin >> temp;
    loc.push_back(temp);
  }

  loc.push_back(0);
  loc.push_back(L);

  sort(loc.begin() , loc.end());

  int start = 1;
  int end = L-1;
  int mid =0;
  int newStore = 0;

  while(start <= end){
    mid = (start+end)/2;
    newStore = 0;
    
    for(int i =0; i<loc.size()-1; i++){
      temp = loc[i+1] - loc[i];
      newStore += (temp/mid);

      if(temp %mid == 0)  newStore--;
    }

    if(newStore <= M){
      ans = mid;
      end = mid-1;
    }
    else{
      start = mid+1;
    }
  }

  cout << ans;
  return 0;
}
