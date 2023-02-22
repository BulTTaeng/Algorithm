#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

queue<pair<int , int>> q;
bool visit[1000001];

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int F,S,G,U,D;

    cin >> F >> S >> G >> U >> D;

    q.push(make_pair(S,0));
    
    memset(visit ,false ,sizeof(visit));

    visit[S] = true;
    int f , s;
    int ans = -1;

    while(!q.empty()){
        f = q.front().first;
        s = q.front().second;
        q.pop();

        if(f == G){
            ans = s;
            break;
        }

        if(f + U <=F){
            if(!visit[f+U]){
                q.push(make_pair(f+U , s+1));
                visit[f+U] = true;
            }
        }

        if(f-D >=1){
            if(!visit[f-D]){
                q.push(make_pair(f-D , s+1));
                visit[f-D] = true;
            }
        }
    }

    if(ans == -1){
        cout << "use the stairs";
    }
    else{
        cout << ans;
    }
    return 0;
}
