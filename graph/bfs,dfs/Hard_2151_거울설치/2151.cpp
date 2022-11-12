#include<iostream>
#include<queue>

using namespace std;
 
struct st
{
    int x;
    int y;
    int dir;
}typedef st;
 
int N;
char inp[51][51];
int visit[51][51][4];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
 
int sx , sy , ex , ey;
queue<st> q;

#define INF 987654321

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    sx = -1 , sy = -1;

    for(int i =0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> inp[i][j];
            if(inp[i][j] == '#'){
                if(sx == -1 && sy == -1){
                    sx = i; sy = j;
                }
                else{
                    ex = i; ey = j;
                }
            }
            visit[i][j][0] = INF;
            visit[i][j][1] = INF;
            visit[i][j][2] = INF;
            visit[i][j][3] = INF;

        }
    }

    st temp;

    for (int i = 0; i < 4; i++)
    {
        temp.x = Start.first;
        temp.y = Start.second;
        temp.Dir = i;
        q.push(temp);
        visit[sx][sy][i] = 0;
    }

    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int dir = q.front().dir;
        q.pop();
 
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int change1 , change2 ;

        if(dir == 0 || dir == 1){
            change1 = 2;
            change2 = 3;
        }
        else{
            change1= 0;
            change2 = 1;
        }
 
        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
 
        if (inp[nx][ny] == '*') continue;
        else if (inp[nx][ny] == '!')
        {
            if (visit[nx][ny][dir] > visit[x][y][dir])
            {
                visit[nx][ny][dir] = visit[x][y][dir];
                temp.x = nx;
                temp.y = ny;
                temp.dir = dir;
                q.push(temp);
            }
 
            if (visit[nx][ny][change1] > visit[x][y][dir] + 1)
            {
                visit[nx][ny][change1] = visit[x][y][dir] + 1;
                temp.x = nx;
                temp.y = ny;
                temp.dir = change1;
                q.push(temp);
            }
 
            if (visit[nx][ny][change2] > visit[x][y][dir] + 1)
            {
                visit[nx][ny][change2] = visit[x][y][dir] + 1;
                temp.x = nx;
                temp.y = ny;
                temp.dir = change2;
                q.push(temp);
            }
        }
        else if (inp[nx][ny] == '.')
        {
            if(visit[nx][ny][dir] > visit[x][y][dir])
            {
                visit[nx][ny][dir] = visit[x][y][dir];
                temp.x = nx;
                temp.y = ny;
                temp.dir = dir;
                q.push(temp);
            }
        }
        else if (inp[nx][ny] == '#')
        {
            if (visit[nx][ny][dir] > visit[x][y][dir])
            {
                visit[nx][ny][dir] = visit[x][y][dir];
            }
        }
    }

    int ans = INF;

    for(int i =0; i<4; i++){
        ans = min(visit[ex][ey][i] , ans);
    }

    cout << ans;
    return 0;
}
