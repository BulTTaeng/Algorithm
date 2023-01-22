#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visit[101][101];
int inp[101][101];

struct st{
    int x;
    int y;
    int d;
}typedef st;

queue<st> q;
int dx[] = { 0 , 0 ,1 , -1};
int dy[] = {1 , -1 , 0 , 0};
 
int N , M ,T;

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M >> T;

    for(int i =1 ; i<=N; i++){
        for(int j = 1; j<=M; j++){
            cin >> inp[i][j];
        }
    }

    int ans =987654321;

    st temp , newone;
    temp.x = 1;
    temp.y = 1;
    temp.d = 0;

    q.push(temp);
    memset(visit , false ,sizeof(visit));
    visit[1][1] = true;

    int cx ,cy , cd;
    int nx , ny;


    while(!q.empty()){
        cx = q.front().x;
        cy = q.front().y;
        cd = q.front().d;
        q.pop();

        if(cx == N && cy == M){
            ans = min(cd, ans);
            break;
        }

        if(inp[cx][cy] == 2){
            ans = min(ans, cd + N - cx + M - cy);
            
        }

        for(int i =0; i<4; i++){
            nx = cx + dx[i];
            ny = cy + dy[i];

            if(nx >=1 && ny>=1 && nx<=N && ny <= M){
                if(!visit[nx][ny] && inp[nx][ny] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.d = cd+1;
                    q.push(newone);
                    visit[nx][ny] = true;
                }
            }
        }


    }

    if(ans == 0 || ans > T){
        cout << "Fail";
    }
    else{
        cout << ans;
    }

    return 0;
}
