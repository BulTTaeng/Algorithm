#include <iostream>
#include <queue>
#include <cstring>

using namespace std;


queue<pair <int , int >> q;
queue<pair<int , int >> fire;

int R ,C;

char inp[1001][1001];
bool visit[1001][1001];

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> R >> C;

    
    memset(visit ,false ,sizeof(visit));

    for(int i =0; i<R ; i++){
        for(int j =0 ; j<C; j++){
            cin >> inp[i][j];

            if(inp[i][j] == 'J'){
                q.push(make_pair(i,j));
                visit[i][j] = true;
            }

            if(inp[i][j] == 'F'){
                fire.push(make_pair(i,j));
            }
        }
    }

    int x,  y , nx , ny;
    int ans = 0;

    while(true){
        ans ++;

        int s = fire.size();

        while(s--){
            x = fire.front().first;
            y= fire.front().second;
            fire.pop();

            for(int i =0; i<4 ; i++){
                nx = x+dx[i];
                ny = y +dy[i];

                if(nx >=0 && ny >= 0 && nx<R && ny<C){
                    if(inp[nx][ny] == '.' || inp[nx][ny] == 'J'){
                        inp[nx][ny] = 'F';
                        fire.push(make_pair(nx , ny));
                    }
                }

            }
        }

        int qs = q.size();

        while(qs--){
            x = q.front().first;
            y= q.front().second;
            q.pop();

            for(int i =0; i<4 ; i++){
                nx = x+dx[i];
                ny = y +dy[i];

                if(nx <0 || ny < 0 || nx>=R || ny>=C){
                    cout << ans;
                    return 0;
                }
                else{
                    if(inp[nx][ny] == '.' && !visit[nx][ny]){
                        inp[nx][ny] = 'J';
                        visit[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }

            }

            inp[x][y] = '.';
        }

        if(q.empty()){
            cout << "IMPOSSIBLE";
            return 0;
        }


    }

    return 0;
}
