#include <iostream>
#include <cstring>

using namespace std;

int R ,C , maxi = 0;
char inp[21][21];
bool alpha[28];

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0 , 0, 1 , -1};

void dfs(int x , int y, int d);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C;

    for(int i =1; i<=R; i++ ){
        for(int j=1; j<=C; j++){
            cin >> inp[i][j];
        }
    }

    memset(alpha , false, sizeof(alpha));

    dfs(1,1,1);

    cout << maxi;
    return 0;
}

void dfs(int x , int y, int d){

    alpha[int(inp[x][y] - 'A')] = true;

    maxi = max(maxi , d);

    for(int i =0; i<4; i++){
        int nx = x+dx[i];
        int ny = y +dy[i];

        if(nx >=1 && ny>=1 && nx <=R && ny <=C){
            if(!alpha[int(inp[nx][ny] - 'A')] ){
                dfs(nx, ny , d+1);
            }   
        }
    }

    alpha[int(inp[x][y] - 'A')] = false;
}
