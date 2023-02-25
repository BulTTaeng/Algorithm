#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool visit[101][101];
int inp[101][101];

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0 , 0 , 1 ,-1};

int M , N ;
int cheese = 0;

vector<int> ans;

void dfs(int x , int y);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int i =0; i<N ; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
            if(inp[i][j] == 1) cheese++;
        }
    }

    int ni , nj;
    ans.push_back(cheese);

    int c = 0;

    while(cheese != 0){
        memset(visit , false ,sizeof(visit));
        dfs(0 , 0);

        for(int i =0; i<N ; i++){
            for(int j =0; j<M; j++){

                if(inp[i][j] == 2){
                    for(int k=0; k<4 ; k++){
                        ni = i + dx[k];
                        nj = j + dy[k];

                        if(ni >=0 && nj>=0 && ni <N && nj<M){
                            if(inp[ni][nj] == 1){
                                cheese--;
                                inp[ni][nj] = 0;
                            }
                            
                        }

                    }
                }

            }
        }
        ans.push_back(cheese);
        c++;
    }
    
    cout << c << "\n";
    
    cout << ans[ans.size() - 2];
    
    return 0;

    
}

void dfs(int x , int y){
    visit[x][y] = true;
    inp[x][y] = 2;

    for(int i =0; i<4 ; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny>=0 && nx <N && ny<M){
            if(!visit[nx][ny] && inp[nx][ny] != 1){
                dfs(nx, ny);
            }
        }
    }
}
