#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N ,  M;
int inp[101][101];
int inp2[101][101];
bool visit[101][101];
queue<pair<int , int> > q;

int dx[] = {-1 , 1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

void dfs(int x , int y);
int melt(int x , int y);


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

    int ans = 0;
    bool b = false;

    while(true){
        memset(visit ,false ,sizeof(visit));
        b= false;

        dfs(0, 0);

        for(int i =0; i<N; i++){
            for(int j =0; j<M; j++){
                if(inp[i][j] > 0){
                    inp2[i][j] = inp[i][j] - melt(i, j);
                }
            }
        }

        for(int i =0; i<N; i++){
            for(int j =0; j<M; j++){
                
                inp[i][j] = inp2[i][j];
                if(inp[i][j] > 0){
                    b = true;
                } 
                
            }
        }

        ans++;

        if(!b){
            cout << ans;
            return 0;
        }        

    }

    return 0 ;
    
}

void dfs(int x , int y){
    visit[x][y] = true;
    q.push(make_pair(x, y));

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny>=0 && nx<N && ny<M){
            if(inp[nx][ny] <= 0 && !visit[nx][ny]){
                dfs(nx, ny);
            }
        }

    }
}

int melt(int x , int y){

    int cnt =0;

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];

        if(nx >=0 && ny>=0 && nx<N && ny<M){
            if(visit[nx][ny]){
                cnt++;
            }
        }

    }

    if(cnt >=2 ){
        return 1;
    }
    else{
        return 0;
    }
}
Footer
© 2022 GitHub, Inc.
Footer navigation
Terms
