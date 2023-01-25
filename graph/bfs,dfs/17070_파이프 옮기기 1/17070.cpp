#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;

int inp[17][17];

struct st{
    int x ;
    int y ;
    int opt;
}typedef st;

queue<st> q; 

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N;

    for(int i= 1; i<=N; i++){
        for(int j = 1; j<=N ; j++){
            cin >> inp[i][j];
        }
    }

    st temp , newone;

    temp.x = 1;
    temp.y=2;
    temp.opt = 1;
    q.push(temp);

    int ans = 0;
    int cx ,cy , option;
    int nx , ny;

    while(!q.empty()){
        cx = q.front().x;
        cy = q.front().y;
        option = q.front().opt;
        q.pop();

        if(cx == N && cy == N){
            ans++;
            continue;
        }

        if(option == 1){ // 가로
            nx = cx;
            ny = cy+1;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 1;
                    q.push(newone);
                }
                
            }

            nx = cx+1;
            ny = cy +1;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1 && inp[nx-1][ny] != 1 && inp[nx][ny-1] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 3;
                    q.push(newone);
                }
            }
        }
        else if(option == 2){ // 세로

            nx = cx+1;
            ny = cy;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 2;
                    q.push(newone);
                }
            }

            nx = cx+1;
            ny = cy +1;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1 && inp[nx-1][ny] != 1 && inp[nx][ny-1] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 3;
                    q.push(newone);
                }
            }

        }
        else{ // 대각선

            nx = cx;
            ny = cy+1;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 1;
                    q.push(newone);
                }
            }

            nx = cx+1;
            ny = cy;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 2;
                    q.push(newone);
                }
            }

            nx = cx+1;
            ny = cy +1;

            if(nx >=1 && ny>=1 && nx<=N && ny<=N){
                if(inp[nx][ny] != 1 && inp[nx-1][ny] != 1 && inp[nx][ny-1] != 1){
                    newone.x = nx;
                    newone.y = ny;
                    newone.opt = 3;
                    q.push(newone);
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}
