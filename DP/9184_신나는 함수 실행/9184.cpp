#include <iostream>
#include <vector>

using namespace std;

int dp[101][101][101];


int w(int a, int b, int c);

int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);

  int a ,b ,c;




  while(true){
    cin >> a >> b >> c;

    if(a == -1 && b == -1 && c == -1) break;

    cout << "w(" << a << ", " << b << ", "<< c <<") = " << w(a,b,c) << endl;

    //ans.push_back(dp[a+50][b+50][c+50]);

  }

  /*for(int i =0; i<ans.size(); i++){
    cout << ans[i] << endl;
  }*/
  return 0;
} 

int w(int a, int b, int c) { 
    if (a <= 0 || b <= 0 || c <= 0) return 1; 
    else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20); 
    else if (dp[a][b][c] != 0) return dp[a][b][c];  
    else if (a < b && b < c) dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);  
    else dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);  return dp[a][b][c]; 
}
