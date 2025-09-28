#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int inp[1002][1002];
bool visit[1002][1002];
int X,Y,N;
queue<pair<int,pair<int,int>>> q;
int ans = 0;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> X >> Y >> N;
    X = X+500;
    Y = Y+500;

    memset(inp, 0, sizeof(inp));
    memset(visit, false, sizeof(visit));

    int x,y;

    for (int i =0; i<N; i++) {
        cin >> x >> y;
        inp[x+500][y+500] = 1;
    }

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push( {0, {500,500}} );
    visit[500][500] = true;

    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        if (x == X && y == Y) {
            ans = time;
            break;
        }

        for (int i =0; i<4; i++) {
            int nx = x +dx[i];
            int ny = y +dy[i];

            if (nx>=0 && nx<=1000 && ny>=0 && nx <=1000) {
                if (!visit[nx][ny] && inp[nx][ny] != 1) {
                    visit[nx][ny]= true;
                    q.push( {time + 1, {nx,ny}} );
                }
            }
        }
        
    }
}
