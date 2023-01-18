#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int T , N;
bool visit[10000101];

struct st{
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int curr;
}typedef st;

st ans[10000101];
vector<int > v;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> T;

    st temp , newone;
    int nx;
    int n1, n2 , n3 , n4 , n5;

    for(int i =0; i<T; i++){
        cin >> N;
        n1=0;n2=0;n3=0;n4=0;n5=0;

      
      n1 += N/60;
      N = N%60;
      

      if(N > 35){
        n1++;
        if(N%10 >=5){
          n3 += (60-N)/10;
          n5 += (10 -N%10);
          cout << n1 << " "<< n2 << " "
            << n3 << " "<< n4 << " "<< n5 << "\n";
        
        }
        else{
          if(N%10 == 0){
            n3 += (60- N)/10;
          }
          else{
            n3 += (60- N)/10 + 1;  
          }
          
          n4 += N%10;
          cout << n1 << " "<< n2 << " "
            << n3 << " "<< n4 << " "<< n5 << "\n";
        
        }
      }

        
      else{
        if(N%10 >5){
          n2 += N/10 +1;
          n5 += (10 -N%10);
          cout << n1 << " "<< n2 << " "
            << n3 << " "<< n4 << " "<< n5 << "\n";
        
        }
        else{
          n2 += N/10;
          n4 += N%10;
          cout << n1 << " "<< n2 << " "
            << n3 << " "<< n4 << " "<< n5 << "\n";
        
        }
      }

      
    }

    return 0;
    
}
