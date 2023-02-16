#include <iostream>
#include <cstring>

using namespace std;

int N;
bool visit[101][101];
char inp[101][101];

int num =0; 
int num_rg = 0;

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0, 0, 1 , -1};

void dfs(int x ,int y , char color);
void dfs_rg(int x ,int y , char color);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j]; 
        }
    }

    memset(visit ,false , sizeof(visit));

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(!visit[i][j]){
                num++;
                dfs(i , j , inp[i][j]);
            }
        }
    }

    memset(visit ,false, sizeof(visit));

    for(int i =0; i<N; i++){
        for(int j =0; j<N; j++){
            if(!visit[i][j]){
                num_rg++;
                dfs_rg(i , j , inp[i][j]);
            }
        }
    }

    cout << num << " " << num_rg;
    return 0;
}

void dfs(int x ,int y , char color){
    visit[x][y] = true;

    for(int i =0; i<4 ; i++){
        int nx = x +dx[i];
        int ny= y + dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(inp[nx][ny] == color && !visit[nx][ny]){
                dfs(nx,ny , color);
            }
        }
    }
}

void dfs_rg(int x ,int y , char color){
    visit[x][y] = true;

    for(int i =0; i<4 ; i++){
        int nx = x +dx[i];
        int ny= y + dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(color == 'R' || color == 'G'){
                if(inp[nx][ny] == 'R' || inp[nx][ny] == 'G'){
                  if(!visit[nx][ny]){
                    dfs_rg(nx, ny , color);
                  }
                }
            }
            else{
                if(inp[nx][ny] == color){
                  if(!visit[nx][ny]){
                    dfs_rg(nx,ny, color);
                  }
                }
            }
        }
    }
}
