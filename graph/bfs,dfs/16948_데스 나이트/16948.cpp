#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

bool visit[202][202];
int N;

struct st{
    int x;
    int y;
    int d;
}typedef st;

int dx[] = {-2 , -2, 0,0,2,2};
int dy[] = {-1 ,1 , -2 , 2,-1, 1 };

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int sx , sy , tx , ty;

    cin >> N;
    cin >> sx >> sy >> tx >> ty;

    memset(visit ,false ,sizeof(visit));

    queue<st>q;
    st temp;
    temp.x = sx;
    temp.y=sy;
    temp.d = 0;
    q.push(temp);
    visit[temp.x][temp.y] = true;
    int f , s;
    int ans = -1;
    st newone;

    while(!q.empty()){
        temp = q.front();
        f= temp.x;
        s= temp.y;
        q.pop();
        
        if(f == tx && s == ty){
            ans = temp.d;
            break;
        }

        for(int i =0; i<6; i++){
            int nx = f+dx[i];
            int ny = s+dy[i];

            if(nx>=0 && ny >=0 && nx<N && ny<N){
                if(!visit[nx][ny]){
                    newone.x = nx;
                    newone.y = ny;
                    newone.d = temp.d+1;
                    q.push(newone);
                    visit[nx][ny] = true;
                }
            }
        }


    }

    cout << ans;
    return 0;


}
