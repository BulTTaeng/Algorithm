#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n , m , k;
vector<pair<int , int>> v;
bool visit[102][102];
bool inp[102][102];
int dx[]= {-1 , 1 ,0 ,0};
int dy[] = {0, 0, 1 , -1};
int temp =0;

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m >> k;
    memset(visit, false ,sizeof(visit));
    memset(inp , false ,sizeof(inp));

    int x , y;
    for(int i =0 ; i<k; i++){
        cin >> x >> y;
        inp[x][y] = true;
        v.push_back(make_pair(x,y));
    }

    int f , s, ans =0;

    for(int i =0; i<v.size(); i++){
        f = v[i].first;
        s = v[i].second;
        if(visit[f][s]){
            continue;
        }

        visit[f][s] = true;
        temp =1;
        dfs(f,s);

        if(temp > ans){
            ans = temp;
        }

    }

    cout << ans;
    return 0;

}

void dfs(int x , int y){
    visit[x][y] = true;

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y +dy[i];

        if(nx >=1 && ny >=1 && nx<=n && ny <=m ){
            if(!visit[nx][ny] && inp[nx][ny] == true){
                temp++;
                dfs(nx, ny);
            }
        }
    }
}
