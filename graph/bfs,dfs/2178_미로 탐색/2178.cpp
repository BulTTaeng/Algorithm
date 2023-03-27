#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n , m;
bool visit[102][102];
char inp[102][102];

struct st{
    int x;
    int y;
    int depth;
}typedef st;

queue<st> q;

int dx[] = {-1, 1, 0 , 0};
int dy[] = {0,0, 1, -1};

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i =1; i<=n ; i++){
        for(int j =1; j <=m; j++){
            cin >>inp[i][j];
        }
    }

    memset(visit , false ,sizeof(visit));
    st temp , newone;
    temp.x = 1;
    temp.y=1;
    temp.depth=1;
    q.push(temp);
    visit[1][1] = true;
    int f, s , ans;

    while(!q.empty()){
        temp =q.front();
        f = temp.x;
        s = temp.y;
        q.pop();

        if(f == n && s == m){
            ans = temp.depth;
            break;
        }

        for(int i=0; i<4 ; i++){
            int nx = f+dx[i];
            int ny = s+dy[i];

            if(nx>=1 && ny>=1 && nx<=n && ny <=m){
                if(!visit[nx][ny] && inp[nx][ny] == '1'){
                    newone.x = nx;
                    newone.y = ny;
                    newone.depth=temp.depth+1;
                    q.push(newone);
                    visit[nx][ny] = true;
                }
            }
        }
    }

    cout << ans;
    return 0;
}
