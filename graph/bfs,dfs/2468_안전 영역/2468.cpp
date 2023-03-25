#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int inp[102][102];
int dx[] = {-1, 1, 0,0};
int dy[] = {0 , 0 ,1 ,-1};
bool visit[102][102];

int n , temp =0, ans = 0;
int nx , ny;

void dfs(int x , int y , int k);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n;
    int mini = 102 , maxi = 0;
    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> inp[i][j];
            mini = min(inp[i][j] , mini);
            maxi = max(inp[i][j] , maxi);
        }
    }

    for(int k = mini-1 ; k<=maxi; k++){
        memset(visit , false ,sizeof(visit));
        temp = 0;

        for(int i=0; i<n; i++){
            for(int j = 0; j<n ; j++){
                if(visit[i][j]){
                    continue;
                }
                if(inp[i][j] > k){
                    dfs(i,j,k);
                    temp++;
                }
            }
        }
        ans = max(ans , temp);
    }// end of k

    cout << ans;
    return 0;
}

void dfs(int x , int y , int k){
    visit[x][y] = true;

    for(int i =0; i<4 ; i++){
        nx = x+dx[i];
        ny = y+dy[i];

        if(nx>=0 && ny>=0 && nx<n && ny<n){
            if(!visit[nx][ny] && inp[nx][ny]>k){
                dfs(nx,ny,k);
            }
        }
    }

    return;
}
