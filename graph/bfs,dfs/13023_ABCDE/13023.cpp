#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> v[2001];
bool visit[2001];
int N , M , ans =0;

void dfs(int x , int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x, y;

    for(int i =0; i<M; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for(int i =0; i<N; i++){
        memset(visit, false ,sizeof(visit));   
        dfs(i , 0);
        if(ans == 1){
            cout << i << " ";
            break;
        }
    }

    cout << ans;
    return 0;
}

void dfs(int x , int d){
    visit[x] = true;

    if(d >=4){
        ans = 1;
        return;
    }

    for(int i =0; i<v[x].size(); i++){
        if(!visit[v[x][i]]){
            dfs(v[x][i] , d+1);
        }
    }
}
