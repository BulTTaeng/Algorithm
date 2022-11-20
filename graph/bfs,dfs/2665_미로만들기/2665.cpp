#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int visit[51][51];
char inp[51][51];
int N;

queue<pair<int , int>> q;

int dx[] = {-1 ,1 , 0 , 0};
int dy[]  = {0 , 0 , 1 , -1};

#define INF 98765432

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i =0; i<N ; i++){
        for(int j =0; j<N; j++){
            cin >> inp[i][j];
        }
    }

    for(int i =0; i<=N; i++){
        for(int j = 0; j<=N; j++){
            
                visit[i][j] = INF;
            
        }
    }

    q.push(make_pair(0,0));

    visit[0][0] = 0;
    int x , y;
    int ans = INF;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if(x == N-1 && y == N-1){
            ans = min(ans , visit[N-1][N-1]);
            continue;
        }

        for(int i =0; i<4 ; i++){
            int nx = x + dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx<N && ny<N){
                if(inp[nx][ny] == '1'){
                    if(visit[nx][ny] > visit[x][y]){
                        visit[nx][ny] = visit[x][y];
                        q.push(make_pair(nx , ny));
                    }
                }
                else{
                    if(visit[nx][ny] > visit[x][y] +1){
                        visit[nx][ny] = visit[x][y] +1;
                        q.push(make_pair(nx , ny));
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
