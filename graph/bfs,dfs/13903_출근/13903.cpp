#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct st{
    int x;
    int y;
    int depth;
}typedef st;

int R,C,N;
int board[1001][1001];
bool visit[1001][1001];
vector<int> dx;
vector<int> dy;
queue<st> q;
int ans = -1;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;

    for (int i =0; i<R; i++) {
        for (int j =0; j<C; j++) {
            cin >> board[i][j];
        }
    }

    cin >> N;

    int a,b;

    for (int i =0; i<N; i++) {
        cin >> a >> b;
        dx.push_back(a);
        dy.push_back(b);
    }

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    st temp;
    
    for (int i =0; i<C; i++) {
        if (board[0][i] == 1) {
            temp.x = 0;
            temp.y = i;
            temp.depth = 0;
            q.push(temp);
            visit[0][i] = true;
        }
    }

    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().depth;
        q.pop();

        if (x == R-1) {
            ans = d;
            break;
        }

        for (int i =0; i<N; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >=0 && nx<R && ny >=0 && ny<C) {
                if (!visit[nx][ny] && board[nx][ny] == 1) {
                    visit[nx][ny] = true;
                    temp.x = nx;
                    temp.y = ny;
                    temp.depth = d + 1;
                    q.push(temp);
                }
            }
        }
    }
}
