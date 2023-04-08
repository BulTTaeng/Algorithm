#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visit[100002];
int a ,b ,n ,m;

int main(){

    cin >> a >> b >> n >> m;

    memset(visit , false ,sizeof(visit));

    queue<pair<int , int>> q;
    q.push(make_pair(n,0));
    int f , depth;

    while(!q.empty()){
        f = q.front().first;
        depth = q.front().second;
        q.pop();

        visit[f] = true;

        if(f == m){
            break;
        }

        if(f +1 <= 100000 ){
            if(!visit[f+1]){
                q.push(make_pair(f+1 , depth+1));
                visit[f+1] = true;
            }
            
        }
        if(f-1 >=0){
            if(!visit[f-1]){
                q.push(make_pair(f-1 , depth+1));
                visit[f-1] = true;
            }
        }

        if(f+a <= 100000){
            if(!visit[f+a]){
                q.push(make_pair(f+a , depth+1));
                visit[f+a] = true;
            }
        }
        if(f+b <= 100000){
            if(!visit[f+b]){
                q.push(make_pair(f+b , depth+1));
                visit[f+b] = true;
            }
        }

        if(f-a >= 0){
            if(!visit[f-a]){
                q.push(make_pair(f-a , depth+1));
                visit[f-a] = true;
            }
        }
        if(f-b >= 0){
            if(!visit[f-b]){
                q.push(make_pair(f-b , depth+1));
                visit[f-b] = true;
            }
        }

        if(f*a <= 100000){
            if(!visit[f*a]){
                q.push(make_pair(f*a , depth+1));
                visit[f*a] = true;
            }
        }
        if(f*b <= 100000){
            if(!visit[f*b]){
                q.push(make_pair(f*b , depth+1));
                visit[f*b] = true;
            }
        }
    }

    cout <<depth;
    return 0;
}
