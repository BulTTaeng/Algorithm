#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool visit[201][201][31];
int inp[201][201];

struct st{
    int x;
    int y;
    int n;
    int d;
}typedef st;

queue<st> q;

int W, H , K;

int dx[] = {-1, 1 , 0 , 0};
int dy[] = {0,0, 1, -1};

int kx[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int ky[] = { -2, -1, 1, 2, 2, 1, -1, -2 };

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> K;

    cin >> W >> H;

    for(int i = 0; i<H; i++){
        for(int j =0; j<W; j++){
            cin >> inp[i][j];
        }
    }

    memset(visit , false ,sizeof(visit));
    st temp , newone ;
    temp.x = 0;
    temp.y = 0;
    temp.n = 0;
    temp.d = 0;

    q.push(temp);
    int x , y , n , d;
    int nx , ny;
    visit[0][0][0] = true;

    int ans = -1;

    while(!q.empty()){
        x = q.front().x;
        y = q.front().y;
        n = q.front().n;
        d = q.front().d;
        q.pop();
        

        if(x == H-1 && y == W-1){
            ans =  d;
            break;
        }

        if(n == K){
            for(int i =0; i<4; i++){
                nx = x+dx[i];
                ny = y + dy[i];

                if(nx >=0 && ny >=0 && nx<H && ny < W){
                    if(!visit[nx][ny][n] && inp[nx][ny] != 1){
                        newone.x = nx;
                        newone.y= ny;
                        newone.n = n;
                        newone.d = d+1;
                        q.push(newone);
                        visit[nx][ny][n] = true;
                    }
                }            
            }
        }

        else{
            for(int i =0; i<4; i++){
                nx = x+dx[i];
                ny = y + dy[i];

                if(nx >=0 && ny >=0 && nx<H && ny < W){
                    if(!visit[nx][ny][n] && inp[nx][ny] != 1){
                        newone.x = nx;
                        newone.y= ny;
                        newone.n = n;
                        newone.d = d+1;
                        q.push(newone);
                        visit[nx][ny][n] = true;
                    }
                }            
            }

            for(int i =0; i<8; i++){
                nx = x+kx[i];
                ny = y + ky[i];

                if(nx >=0 && ny >=0 && nx<H && ny < W){
                    if(!visit[nx][ny][n+1] && inp[nx][ny] != 1){
                        newone.x = nx;
                        newone.y= ny;
                        newone.n = n+1;
                        newone.d = d+1;
                        q.push(newone);
                        visit[nx][ny][n+1] = true;
                    }
                }            
            }
        }
    }

    cout << ans;
    return 0;

}
