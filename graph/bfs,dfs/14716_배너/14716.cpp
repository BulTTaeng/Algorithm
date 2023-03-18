#include <iostream>
#include <cstring>

using namespace std;

bool visit[252][252];
int inp[252][252];

int dx[] = {-1, 1, 0, 0 ,-1, -1 , 1,1};
int dy[] = {0,0,1,-1 , -1, 1, 1, -1};
int N , M;

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    
    for(int i =0; i<N;i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit , false ,sizeof(visit));
    
    int ans = 0;

    for(int i =0; i<N;i++){
        for(int j =0; j<M ; j++){
            if(!visit[i][j] && inp[i][j] == 1){
                dfs(i,j);
                ans++;
            }
        }
    }

    cout << ans;
    return 0;
}

void dfs(int x , int y){
    visit[x][y] = true;

    for(int i =0; i<8 ; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny >=0 && nx<N && ny <M){
            if(!visit[nx][ny] && inp[nx][ny] == 1){
                dfs(nx , ny);
            } 
        }
    }
}
