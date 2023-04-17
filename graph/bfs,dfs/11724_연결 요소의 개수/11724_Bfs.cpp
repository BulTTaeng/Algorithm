#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

bool visit[1002];
vector<int> v[1002];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n , m ,x,y;

    cin >> n >> m;

    for(int i = 0 ;i<m; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visit , false ,sizeof(visit));

    int curr;
    int ans = 0;

    for(int j= 1 ; j<=n; j++){
        q.push(j);

        if(!visit[j]){
            ans++;
        }

        visit[j] = true;

        while(!q.empty()){
            curr = q.front();
            q.pop();
        
            for(int i =0; i<v[curr].size(); i++){
                if(!visit[v[curr][i]] ){
                    q.push(v[curr][i]);
                    visit[v[curr][i]] = true;
                }
            }    
        }

    }

    cout << ans;
    return 0;
}
