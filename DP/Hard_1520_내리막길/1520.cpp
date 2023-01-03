#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int inp[501][501];
int visit[501][501];

int N , M;

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N; i++){
        for(int j = 0 ; j<M; j++){
            cin >> inp[i][j];
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            visit[i][j] = -1;
        }
    }

    int x = dfs(0,0);

    cout << x;

    return 0;

}

int dfs(int x , int y){

    if(x == N-1 && y == M-1){
        return 1;
    }

    if(visit[x][y] != -1 ){
        return visit[x][y];
    }

    visit[x][y] = 0;

    for(int i = 0; i<4 ; i++){
        int nx = x+ dx[i];
        int ny = y+ dy[i];
        
        if(nx >=0 && ny >=0 && nx<N && ny < M){
            if(inp[nx][ny] < inp[x][y]){
                visit[x][y] += dfs(nx, ny);
            }
        }
    }

    return visit[x][y];
    
}
