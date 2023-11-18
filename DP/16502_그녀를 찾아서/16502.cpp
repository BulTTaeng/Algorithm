#include <iostream>
#include <vector>

using namespace std;

vector<double> A;
vector<double> B;
vector<double> C;
vector<double> D;


int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  double edge[4][4] = { 0, };
  int n , m;
  char from , to;
  double temp;

  cin >> n >> m;

  for(int i =0; i<m; i++){
    cin >> from >> to >> edge[from-65][to-65]; 
  }

  double per[4][11] = {0, };

  for(int i = 0; i<4; i++){

    for(int j =0; j<4; j++){
      per[i][0] += edge[j][i] * 0.25;  
    }
    per[i][0] = per[i][0] * 100;
  }

  for(int i = 1; i<n; i++){
    
    for(int j = 0; j<4; j++){
      for(int k =0; k<4; k++){
        per[j][i] += per[k][i-1] * edge[k][j];
      }
    }

  }

  for(int i = 0; i<4; i++){
    cout << per[i][n-1] << endl;  
  }

  return 0;

} 
