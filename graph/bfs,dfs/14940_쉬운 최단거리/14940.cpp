#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int inp[1001][1001];
bool visit[1001][1001];
int ans[1001][1001];

int N  ,M;

int sx, sy;

struct st
{
    int x ;
    int y;
    int d;
}typedef st;

queue<st> q;

int dx[] ={-1, 1, 0, 0};
int dy[] = {0, 0, 1 ,-1};

void bfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >>  N >> M;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 2){
                sx=i;
                sy=j;
            }
        }
    }
    memset(visit , false, sizeof(visit));
    visit[sx][sy] = true;
    ans[sx][sy] = 0;
    bfs(sx,sy);

    for(int i =0; i<N; i++){
        for(int j =0; j<M ; j++){
            if( !visit[i][j] && inp[i][j] == 1){
                ans[i][j] = -1;
            }
            else if(inp[i][j] == 0){
                ans[i][j] = 0;
            }
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M ; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

void bfs(int x , int y){
    st temp;
    temp.x = x;
    temp.y = y;
    temp.d = 0;
    q.push(temp);
    st newone;

    while(!q.empty()){
        newone = q.front();
        q.pop();

        for(int i =0; i<4 ; i++){
            int nx = newone.x  + dx[i];
            int ny = newone.y + dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(!visit[nx][ny] && inp[nx][ny] == 1){
                    temp.x = nx;
                    temp.y = ny;
                    temp.d = newone.d+1;
                    q.push(temp);
                    ans[nx][ny] = newone.d+1;
                    visit[nx][ny] = true;
                }
            }
        }
    }
    
}
