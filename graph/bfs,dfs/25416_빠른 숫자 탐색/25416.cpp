#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int board[5][5];
bool visit[5][5];
int dx[] = {-1, 1, 0,0};
int dy[] = {0,0,1,-1};
int R,C;
int ans = -1;
queue<pair<int,pair<int,int>>> q;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i =0; i<5; i++) {
        for (int j =0; j<5; j++) {
            cin >> board[i][j];
        }
    }

    cin >> R >> C;

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;

    return 0;
}

void bfs() {
    q.push({0,{R,C}});
    visit[R][C] = true;    

    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dis = q.front().first;
        q.pop();

        if (board[x][y] == 1) {
            ans = dis;
            break;
        }

        for (int i =0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx>=0 && nx<5 && ny>=0 && ny <5) {
                if (!visit[nx][ny] && board[nx][ny] != -1) {
                    visit[nx][ny] = true;
                    q.push({dis + 1, {nx,ny}});
                }
            }
        }
    }
}
