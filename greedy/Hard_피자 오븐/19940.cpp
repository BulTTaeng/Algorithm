#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int T , N;
bool visit[67];

struct st{
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int curr;
}typedef st;

queue<st> q;
st ans[67];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    
    int nx;
    st temp , newone;

    temp.n1 = 0;
    temp.n2 = 0;
    temp.n3 = 0;
    temp.n4 = 0;
    temp.n5 = 0;
    temp.curr = 0;
    q.push(temp);
    
    memset(visit ,false ,sizeof(visit));
    visit[0] = true;

    while(!q.empty()){

        newone = q.front();
        q.pop();       

        nx = newone.curr - 1;
            if(nx >= 0){
                if(!visit[nx]){
                    temp.n1= newone.n1;
                  temp.n2= newone.n2;
                  temp.n3= newone.n3;
                  temp.n4= newone.n4;
                  temp.n5= newone.n5+1;
                  temp.curr= nx;
                    q.push(temp);
                  ans[nx] = temp;
                    visit[nx] = true;
                }
            }

          nx = newone.curr + 1;
            if(nx <=66){
                if(!visit[nx]){
                    temp.n1= newone.n1;
                  temp.n2= newone.n2;
                  temp.n3= newone.n3;
                  temp.n4= newone.n4+1;
                  temp.n5= newone.n5;
                  temp.curr= nx;
                    q.push(temp);
                  ans[nx] = temp;
                    visit[nx] = true;
                }
            }

          nx = newone.curr - 10;
            if(nx >= 0){
                if(!visit[nx]){
                    temp.n1= newone.n1;
                  temp.n2= newone.n2;
                  temp.n3= newone.n3+1;
                  temp.n4= newone.n4;
                  temp.n5= newone.n5;
                  temp.curr= nx;
                    q.push(temp);
                  ans[nx] = temp;
                    visit[nx] = true;
                }
            }

          nx = newone.curr + 10;
            if(nx <=66){
                if(!visit[nx]){
                    temp.n1= newone.n1;
                  temp.n2= newone.n2+1;
                  temp.n3= newone.n3;
                  temp.n4= newone.n4;
                  temp.n5= newone.n5;
                  temp.curr= nx;
                    q.push(temp);
                  ans[nx] = temp;
                    visit[nx] = true;
                }
            }

          nx = newone.curr + 60;
            if(nx <=66){
                if(!visit[nx]){
                    temp.n1= newone.n1+1;
                  temp.n2= newone.n2;
                  temp.n3= newone.n3;
                  temp.n4= newone.n4;
                  temp.n5= newone.n5;
                  temp.curr= nx;
                    q.push(temp);
                    ans[nx] = temp;
                    visit[nx] = true;
                }
            }

          
        }

    cin >> T;

    for(int i =0; i<T; i++){
        cin >> N;
        
        if(N <=60){
            cout << ans[N].n1 << " " << ans[N].n2 << " "<< ans[N].n3 << " "<< ans[N].n4 << " "<< ans[N].n5 << "\n";
        }
        else{
            cout << ans[N%60].n1 + N/60 << " " << ans[N%60].n2 << " "<< ans[N%60].n3 << " "<< ans[N%60].n4 << " "<< ans[N%60].n5 << "\n";
        }



        
    }

    return 0;
    
}
