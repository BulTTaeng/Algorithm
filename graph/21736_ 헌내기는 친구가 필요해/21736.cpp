#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int ans = 0;
int sx, sy; // 시작 x,y 좌표

char campus[602][602];
bool visit[602][602];

int dx[] = {-1, 1 ,0 ,0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    
    memset(visit, false, sizeof(visit));

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            cin >> campus[i][j];

            if (campus[i][j] == 'I') {
                sx = i;
                sy = j;
            }
        }
    }

    dfs(sx, sy);

    if (ans == 0) {
        cout << "TT";
    } else {
        cout << ans;
    }

    return 0;
}

void dfs(int x, int y) {

    visit[x][y] = true;

    if (campus[x][y] == 'P') {
        ans++;
    }

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <0 || ny<0 || nx>=N || ny >= M) continue;

        if (!visit[nx][ny] && campus[nx][ny] != 'X') {
            dfs(nx, ny);
        }
    }
}
