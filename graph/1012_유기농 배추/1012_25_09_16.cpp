#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int T, N, M, K;

queue<pair<int,int>> q;
vector<pair<int,int>> v;

int inp[52][52];
bool visit[52][52];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int ans = 0;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    int x,y;

    while(T--) {
        ans = 0;
        memset(visit, false, sizeof(visit));
        memset(inp, 0, sizeof(inp));
        
        q = queue<pair<int,int>>();
        v = vector<pair<int,int>>();
        
        cin >> M >> N >> K;
        
        for (int i =0; i<K; i++) {
            cin >> x >> y;
            inp[x][y] = 1;
            v.push_back({x,y});
        }

        bfs();

        cout << ans << "\n";
    }

    return 0;
}

void bfs() {
    for (int i =0; i<K; i++) {
        if (!visit[v[i].first][v[i].second]) {
            q.push(v[i]);
            visit[v[i].first][v[i].second] = true;
            ans++;
        }
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
    
            for (int j =0; j<4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (!visit[nx][ny] && inp[nx][ny] == 1) {
                    q.push({nx,ny});
                    visit[nx][ny] = true;
                }
            }
        }
    }
}
