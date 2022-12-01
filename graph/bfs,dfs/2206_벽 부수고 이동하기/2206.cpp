#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N , M;
bool visit[1001][1001][2];
char inp[1001][1001];

int dx[] = {-1 , 1, 0 , 0};
int dy[] = { 0 , 0 , 1 , -1};

struct st{
    int x;
    int y;
    int b;
    int d;
}typedef st;

queue<st> q;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    for(int  i = 0 ; i<N; i++){
        for(int j =0; j<M; j++){
            cin >> inp[i][j];
        }
    }

    st temp , newone;
    temp.x = 0;
    temp.y = 0;
    temp.b = 0;
    temp.d = 1;

    q.push(temp);

    memset(visit ,false ,sizeof(visit));
    
    visit[0][0][0] = true;
    int x, y , b, d;

    int ans = -1;

    while(!q.empty()){
        x= q.front().x;
        y = q.front().y;
        b = q.front().b;
        d = q.front().d;
        q.pop();

        if(x == N-1 && y == M-1){
            ans = d;
            break;
        }

        for(int i =0 ; i<4 ;i++){
            int nx = x+dx[i];
            int ny= y+dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(inp[nx][ny] == '1'){
                    if(b == 0){
                        if(!visit[nx][ny][1]){
                            temp.x = nx;
                            temp.y = ny;
                            temp.b = 1;
                            temp.d = d+1;
                            q.push(temp);
                            visit[nx][ny][1] = true;
                        }
                    }
                }
                else{
                    if(!visit[nx][ny][b]){
                        temp.x = nx;
                        temp.y = ny;
                        temp.b = b;
                        temp.d = d+1;
                        q.push(temp);
                        visit[nx][ny][b] = true;
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
