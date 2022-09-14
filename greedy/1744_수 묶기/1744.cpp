#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
long long ans = 0;
priority_queue<int>p;
priority_queue<int>m;
int num =0;
int count = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  cin >> N;

  int temp;
  long long tans =0;
  
  for(int i =0; i<N; i++){
    cin >> temp;
    if(temp <=0){
      m.push(abs(temp));
    }
    else if(temp ==1){
      ans++;
    }
    else{
      p.push(temp);
    }
    tans += temp;
  }

  int n1, n2;

  while(!p.empty()){
    n1 =p.top();
    p.pop();

    if(!p.empty()){
      n2 = p.top();
      p.pop();
      ans += n1*n2;
    }
    else{
      ans += n1;
    }
    
  }

  while(!m.empty()){
    n1 =m.top();
    m.pop();

    if(!m.empty()){
      n2 = m.top();
      m.pop();

      ans += (n1*n2);
    }
    else{ // 하나 남음 , 그냥 빼야함
      ans -= n1;
      break;
    }
  }

  cout << max(ans , tans);
  return 0;
}
