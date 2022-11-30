#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int N , M , s =0, roomnum = 0;
int maxbreak = 0;
int inp[51][51];
int visit[51][51];
vector<int> v;

int dx[] = {0 , 0 , 1 , -1};
int dy[] = {1 , -1  ,0 , 0};

void dfs(int x , int y , int num);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit ,0 ,sizeof(visit));

    int maxi = 0;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            if(visit[i][j] == 0){
                s = 0;
                roomnum++;
                dfs(i, j, roomnum);
                v.push_back(s);
                maxi = max(maxi , s);
            }
        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            for(int k =0; k<4 ; k++){
                int nx = i +dx[k];
                int ny = j + dy[k];

                if(nx>=0 && ny >=0 && nx<N && ny<M){
                    if(visit[nx][ny] != visit[i][j]){
                        maxbreak = max(maxbreak , v[visit[nx][ny] - 1] + v[visit[i][j] -1]);
                    }
                }
            }
        }
    }
    
    cout << roomnum<<"\n";
    cout << maxi << "\n";
    cout << maxbreak;
    return 0;    
}

void dfs(int x , int y , int num){

    visit[x][y] = num;
    s++;

    if(inp[x][y] == 0){

        for(int i =0; i<4 ; i++){
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 1){

        for(int i =0; i<4 ; i++){
            if(i == 1){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 2){

        for(int i =0; i<4 ; i++){
            if(i == 3){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
        
    }
    else if(inp[x][y] == 3){

        for(int i =0; i<4 ; i++){
            if(i == 3 || i == 1){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
        
    }
    else if(inp[x][y] == 4){
        for(int i =0; i<4 ; i++){
            if(i == 0){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
        
    }
    else if(inp[x][y] == 5){
        for(int i =0; i<4 ; i++){
            if(i == 1 || i == 0){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
        
    }
    else if(inp[x][y] == 6){
        for(int i =0; i<4 ; i++){
            if(i == 3 || i == 0){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 7){

        
            int nx = x +dx[2];
            int ny = y + dy[2];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        
    }
    else if(inp[x][y] == 8){
        for(int i =0; i<4 ; i++){
            if(i == 2){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
        
    }
    else if(inp[x][y] == 9){

        for(int i =0; i<4 ; i++){
            if(i == 2 || i == 1){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 10){

        for(int i =0; i<4 ; i++){
            if(i == 2 || i == 3){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 11){

            int nx = x +dx[0];
            int ny = y + dy[0];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        
    }
    else if(inp[x][y] == 12){

        for(int i =0; i<4 ; i++){
            if(i == 2 || i == 0){
                continue;
            }
            int nx = x +dx[i];
            int ny = y + dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        }
    }
    else if(inp[x][y] == 13){
        
            int nx = x +dx[3];
            int ny = y + dy[3];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
        
    }
    else if(inp[x][y] == 14){
            int nx = x +dx[1];
            int ny = y + dy[1];

            if(nx>=0 && ny >=0 && nx<N && ny<M){
                if(!visit[nx][ny]){
                    dfs(nx, ny ,num);
                }
            }
    }
    
}

