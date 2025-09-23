#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, T;
int inp[1002][1002];
bool visit[1002][1002];
queue<pair<int,int>> q;
int ans = 0;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int r,g,b;

    for (int i = 0; i<N; i++) {
        for (int j =0; j<M; j++) {
            cin >> r >> g >> b;
            int average = (r + g + b) / 3;
            inp[i][j] = average;
        }
    }

    cin >> T;

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    for (int i =0;i<N; i++) {
        for (int j =0; j<M; j++) {
            if (inp[i][j] >= T && !visit[i][j]) {
                q.push({i,j});
                ans++;
                visit[i][j] = true;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k =0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >=0 && nx <N && ny>=0 && ny<M) {
                            if (!visit[nx][ny] && inp[nx][ny] >= T) {
                                q.push({nx,ny});
                                visit[nx][ny] = true;
                            }
                        }
                    }
                }
            }
        }
    }
}
