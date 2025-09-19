#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int T, H, W;
char inp[102][102];
bool visit[102][102];
queue<pair<int,int>> q;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while(T--) {
        cin >> H >> W;
        memset(inp, '.', sizeof(inp));
        
        for (int i =0; i<H; i++) {
            for(int j =0; j<W; j++) {
                cin >> inp[i][j];
            }
        }

        memset(visit, false, sizeof(visit));
        
        q = queue<pair<int,int>>();
        
        cout << bfs() << "\n";
    }
    return 0;
}

int bfs() {
    int ans = 0;

    for (int i=0;i<H; i++) {
        for (int j =0; j<W; j++) {
            if (!visit[i][j] && inp[i][j] == '#') {
                q.push({i,j});
                visit[i][j] = true;
                ans++;

                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    for (int k =0; k<4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (!visit[nx][ny] && inp[nx][ny] == '#') {
                            visit[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    return ans;
}
