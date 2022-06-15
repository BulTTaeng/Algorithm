#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N , M;
char inp[1001][1001];
int visit[1001][1001];

int ans = 0;

void bfs(int i , int j , int c);

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
    memset(visit , 0 ,sizeof(visit));

    int v = 1;

    for(int i =0; i<N; i++){
        for(int j =0; j<M; j++){
            if(visit[i][j] == 0){
                bfs(i, j , v);
                v++;
            }
        }
    }

    cout << ans;
    return 0;
}

void bfs(int i , int j , int c){

    queue<pair<int , int>> q;
    q.push({i,j});
    visit[i][j] = c;
    int x , y , nx , ny;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(inp[x][y] == 'U'){
            nx = x -1;
            ny = y;

            if(nx >=0 && ny>=0 && nx<N && ny<M){
                if(visit[nx][ny] == 0){
                    q.push({nx , ny});
                    visit[nx][ny] = c;
                }
                else{
                    if(visit[nx][ny] == c){
                        ans++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                ans++;
                break;
            }
        }
        else if(inp[x][y] == 'D'){
            nx = x +1;
            ny = y;

            if(nx >=0 && ny>=0 && nx<N && ny<M){
                if(visit[nx][ny] == 0){
                    q.push({nx , ny});
                    visit[nx][ny] = c;
                }
                else{
                    if(visit[nx][ny] == c){
                        ans++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                ans++;
                break;
            }
        }
        else if(inp[x][y] == 'L'){
            nx = x;
            ny = y-1;

            if(nx >=0 && ny>=0 && nx<N && ny<M){
                if(visit[nx][ny] == 0){
                    q.push({nx , ny});
                    visit[nx][ny] = c;
                }
                else{
                    if(visit[nx][ny] == c){
                        ans++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                ans++;
                break;
            }
        }
        else if(inp[x][y] == 'R'){
            nx = x;
            ny = y+1;

            if(nx >=0 && ny>=0 && nx<N && ny<M){
                if(visit[nx][ny] == 0){
                    q.push({nx , ny});
                    visit[nx][ny] = c;
                }
                else{
                    if(visit[nx][ny] == c){
                        ans++;
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                ans++;
                break;
            }
        }
    }
}
