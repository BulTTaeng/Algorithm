#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
vector<int> v;
int maxi = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);

  cin >> T;
  int temp;
  
  while(T--){
    cin >> N;
    v.clear();
    maxi = 0;
    
    for(int i =0; i<N; i++){
      cin >> temp;
      v.push_back(temp);
    }

    sort(v.begin() , v.end() );

    maxi = max(v[2]-v[0] , v[1] - v[0]);

    for(int i =3; i<N; i++){
      maxi = max(maxi , v[i]-v[i-2]);
    }

    cout << maxi << "\n";
    
  }

  return 0;
  
}
