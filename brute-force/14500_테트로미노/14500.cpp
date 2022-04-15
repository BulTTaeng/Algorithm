#include <iostream>
#include <cstring>

using namespace std;

int N , M;

int dx[] = {-1, 1 , 0, 0};
int dy[] = {0, 0 , 1, -1};

int inp[501][501];
bool visit[501][501];

int ans = 0;

void dfs(int sum , int depth , int x , int y);
void case5(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit , false ,sizeof(visit));

    for(int i =0; i<N; i++){
        for(int j =0; j<M ; j++){
            visit[i][j] = true;
            dfs(inp[i][j] , 0 , i, j);
            visit[i][j]  = false;
            case5(i,j);
        }
    }

    cout << ans;
    return 0;
}

void dfs(int sum , int depth , int x , int y){

    if(depth == 3){
        ans = max(ans , sum);
        return;
    }

    for(int i =0; i<4; i++){
        int nx = dx[i] + x;
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<M){
            if(!visit[nx][ny]){
                visit[nx][ny] =true;
                dfs(sum+inp[nx][ny] , depth+1 , nx, ny);
                visit[nx][ny] = false;
            }
        }
    }
}

void case5(int x , int y){
    
    if(x+1 < N && y-1 >= 0 && y+1 <M){
        ans = max(ans , inp[x][y] + inp[x+1][y] + inp[x][y+1] + inp[x][y-1] );
    }

    if(y+1 <M && x-1 >=0 && x+1 <N){
        ans = max(ans , inp[x][y] + inp[x+1][y] + inp[x-1][y] + inp[x][y+1] );
    }

    if(x-1 >=0 && y-1 >=0 && y+1 <M){
        ans = max(ans , inp[x][y] + inp[x-1][y] + inp[x][y-1] + inp[x][y+1] );
    }

    if(x+1 <N && x-1 >=0 && y-1 >=0){
        ans = max(ans , inp[x][y] + inp[x+1][y] + inp[x-1][y] + inp[x][y-1] );
    }
    
}
