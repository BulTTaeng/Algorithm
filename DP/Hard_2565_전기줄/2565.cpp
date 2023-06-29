#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct{
  int x;
  int y;
} typedef s;

vector<s> inp;
int dp[102];
int n;

bool compare(const s& s1 ,const s& s2){
  return s1.x < s2.x;
}

int find_inc();

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  cin >> n;

  s temp;

  for(int i =0; i<n; i++){
    cin >> temp.x >> temp.y;
    inp.push_back(temp);  
  }

  sort(inp.begin(), inp.end() , compare);

  int ans = find_inc();
  cout << n-ans;
  return 0;
}

int find_inc(){
  int maxi = 0;
  dp[0] = 1;
  
  for(int i =1; i<n; i++){
    dp[i] = 1;
    for(int j = 0; j<i; j++){
      
      if(inp[i].y > inp[j].y){
        dp[i] = max(dp[j] +1,dp[i]);
      }
      
    }
    if(maxi < dp[i]){
      maxi = dp[i];
    }

  }

  return maxi;
}
