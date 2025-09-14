#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int graph[302][302];
bool visit[302][302];

int dx[] = {0, 1};
int dy[] = {1, 0};

queue<pair<int,int>> q;

bool bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i=1; i<=M; i++) {
        for (int j=1; j<=N; j++) {
            cin >> graph[i][j];
        }
    }

    memset(visit, false, sizeof(visit));

    bool ans = bfs();

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    return 0;
}

bool bfs() {
    q.push({1,1});
    visit[1][1] = true;
    
    while(!q.empty()) {
        pair<int,int> temp = q.front();
        q.pop();

        int x = temp.first;
        int y = temp.second;

        if (x == M && y == N) {
            return true;
        }

        for (int i =0; i<2; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (!visit[nx][ny] && graph[nx][ny] == 1) {
                visit[nx][ny] = true;
                q.push({nx,ny});
            }
        }
    }

    return false;
}
