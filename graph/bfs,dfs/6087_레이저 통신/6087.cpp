#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int M , N;
char inp[101][101];
int visit[101][101][4];

struct st{
    int x;
    int y;
    int from;
}typedef st;

//0 -> 동 1->서 2-> 남 3- > 북

queue<st>q;

int dx[] = {0,0 ,-1 , 1};
int dy[] = {-1, 1 , 0 , 0};

#define MAX 98765432

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> M >> N;
    int sx = -1, sy = -1 , ex , ey;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 'C'){
                if(sx == -1){
                    sx = i;
                    sy = j;
                }
                else{
                    ex = i;
                    ey = j;
                }
            }

        }
    }

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            for(int k = 0 ; k < 4; k++){
                if(i == sx && j == sy){
                    visit[i][j][k] = 0;
                }
                else{
                    visit[i][j][k] = MAX;
                }
            }
        }
    }

    st temp;
    temp.x = sx;
    temp.y = sy;

    if(inp[sx][sy-1] != '*'){
        temp.from = 0;
        q.push(temp);
    }
    
    if(inp[sx][sy+1] != '*' ){
        temp.from = 1;
        q.push(temp);
    }

    if(inp[sx-1][sy] != '*'){
        temp.from = 2;
        q.push(temp);
    }
    
    if(inp[sx+1][sy] != '*'){
        temp.from =3;
        q.push(temp);
    }

    int x , y , f , c1 , c2;

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        f = q.front().from;
        q.pop();

        if(f == 0 || f == 1){
            c1 = 2;
            c2 = 3;
        }
        else if(f == 2 || f == 3){
            c1 = 0;
            c2 = 1;
        }

        int nx = x+ dx[f];
        int ny = y+dy[f];

        if(nx<0 || ny < 0 || nx>=N || ny>=M) continue; 

        if(inp[nx][ny] == '.'){
            if(visit[nx][ny][f] > visit[x][y][f]){
                visit[nx][ny][f] = visit[x][y][f];
                temp.x = nx;
                temp.y = ny;
                temp.from = f;
                q.push(temp);
            }
            if(visit[nx][ny][c1] > visit[x][y][f] + 1){
                visit[nx][ny][c1] = visit[x][y][f] +1;
                temp.x = nx;
                temp.y = ny;
                temp.from = c1;
                q.push(temp);
            }
            if(visit[nx][ny][c2] > visit[x][y][f] + 1){
                visit[nx][ny][c2] = visit[x][y][f] +1;
                temp.x = nx;
                temp.y = ny;
                temp.from = c2;
                q.push(temp);
            }

            
        }

        else if(inp[nx][ny] == 'C'){
            if(visit[nx][ny][f] > visit[x][y][f]){
                visit[nx][ny][f] = visit[x][y][f];
            }
        }


    }

    int ans = MAX;

    for(int i =0; i<4; i++){
        ans = min(ans , visit[ex][ey][i]);
    }
    cout << ans;
    return 0;
}
