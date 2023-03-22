#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool visit[20002];
vector<int> v[20002];
queue<pair<int , int>> q;
int _depth[20002];

int N ,M;

int maxd = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >>M;
    int x , y;
    for(int i =0; i<M; i++){
        cin >> x>> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visit, false ,sizeof(visit));

    q.push(make_pair(1,0));
    visit[1] = true;
    int f , s ;

    int ans = 0;
    int num = 0;

    while(!q.empty()){
        f = q.front().first;
        s= q.front().second;
        q.pop();

        maxd = max(maxd , s);
        _depth[f] = s;
        for(int i =0; i<v[f].size(); i++){
            if(!visit[v[f][i]]){
                q.push(make_pair(v[f][i] , s+1));
                visit[v[f][i]] = true;
            }
        }

        
    }
    
    for(int i =1; i<=N; i++){
        if(_depth[i] == maxd){
            if(ans == 0)
                ans = i;
            num++;
        }
        
    }

    cout << ans << " " << _depth[ans] << " " <<num;

    return 0;
}
