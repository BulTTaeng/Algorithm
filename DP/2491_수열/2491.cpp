#include <iostream>
#include <vector>

using namespace std;

int dp_in[100002];
int dp_de[100002];

vector<int> num;

int find_max(int a, int b);

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);

  int n , input;
  cin >> n;

  for(int i=0; i<n; i++){
    cin >> input;
    num.push_back(input);
  }

  dp_in[0] = 1;
  dp_de[0] = 1;

  int max = 1;

  for(int i =1; i <n; i++){
    if(num[i] >= num[i-1]){
      dp_in[i] = dp_in[i-1] + 1;
    }
    else{
      dp_in[i] = 1;
    }

    if (num[i] <= num[i-1]){
      dp_de[i] = dp_de[i-1] +1;
    }
    else{
      dp_de[i] = 1;
    }
    
    max = find_max(max , dp_de[i]);
    max = find_max(max, dp_in[i]);
  }

  cout << max;
  return 0;
}


int find_max(int a, int b){
  if(a>b) return a;
  else return b;
}
