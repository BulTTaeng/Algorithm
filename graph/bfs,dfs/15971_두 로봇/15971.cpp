#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

bool visit[100001];
vector<pair<int , int >> v[100001];

int dis1[100001];
int dis2[100001];


int N , S ,E;

void dfs(int x , int w);
void dfs_end(int x , int w);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> S >> E;
    int x, y ,w;

    if(S == E){
        cout << 0;
        return 0;
    }
    if(N == 1){
        cout << 0;
        return 0;
    }

    for(int i =1; i<N ; i++){
        cin >> x>> y >> w;
        v[x].push_back(make_pair(y,w));
        v[y].push_back(make_pair(x,w));
    }

    memset(dis1 , 0 , sizeof(dis1));
    memset(visit, false ,sizeof(visit));

    dfs(S , 0);

    memset(dis2 , 0 , sizeof(dis2));
    memset(visit, false ,sizeof(visit));

    dfs_end(E , 0);
    int ans = 987654321;

    for(int i =1; i<=N; i++){
        for(int j =0; j<v[i].size() ; j++){
            ans = min( dis2[v[i][j].first] + dis1[i] , ans );
            //cout << i << " " << v[i][j].first << "  " << dis2[v[i][j].first] + dis1[i] << "\n";
        }
    }

    cout << ans;
    return 0;

}

void dfs(int x , int w){
    visit[x] = true;
    dis1[x] += w;

    for(int i =0; i<v[x].size() ; i++){
        if(!visit[v[x][i].first]){
            dfs(v[x][i].first , w+v[x][i].second);
        }
    }
}

void dfs_end(int x , int w){
    visit[x] = true;
    dis2[x] += w;

    for(int i =0; i<v[x].size() ; i++){
        if(!visit[v[x][i].first]){
            dfs_end(v[x][i].first , w+v[x][i].second);
        }
    }
}
