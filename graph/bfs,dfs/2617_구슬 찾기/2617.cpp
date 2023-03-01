#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> htol[100];
vector<int> ltoh[100];
bool ans[100];
bool visit[100];

int h , l;

int N ,M;

void dfs_h(int x);
void dfs_l(int x);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;
    int x,y;
    for(int i =0; i<M; i++){
        cin >> x >> y;

        htol[x].push_back(y);
        ltoh[y].push_back(x);
    }

    memset(ans , true ,sizeof(ans));

    for(int i =1; i<=N; i++){
        
        h = 0;
        l = 0;
        memset(visit , false ,sizeof(visit));
        dfs_h(i);

        memset(visit , false ,sizeof(visit));
        dfs_l(i);

        if(h >= (N+1)/2 ){
            ans[i] = false;
        }

        if(l >= (N+1)/2 ){
            ans[i] = false;
        }
    }

    int num =0;

    for(int i = 1 ; i<=N; i++){
        //cout << ans[i] << " ";
        if(!ans[i]){
            num++;
        }
    }

    cout << num;
    return 0;
    
}

void dfs_h(int x){
    visit[x] = true;

    for(int i =0; i<htol[x].size(); i++){
        if(!visit[ htol[x][i] ]){
            dfs_h( htol[x][i] );
            h++;
        }
    }
}

void dfs_l(int x){
    visit[x] = true;

    for(int i =0; i<ltoh[x].size(); i++){
        if(!visit[ ltoh[x][i] ]){
            dfs_l( ltoh[x][i] );
            l++;
        }
    }
}

