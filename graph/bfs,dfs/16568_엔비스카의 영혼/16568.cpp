#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N,a,b;
int ans = 0;
bool visit[1000001];
queue<pair<int,int>> q;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> a >> b;

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push({0,N});
    visit[N] = true;
    
    while(!q.empty()) {
        int depth = q.front().first;
        int x = q.front().second;
        q.pop();

        if (x == 0) {
            ans = depth;
            break;
        }

        int nx = x - a - 1;
        if (nx >= 0 && !visit[nx]) {
            q.push({depth+1, nx});
            visit[nx] = true;
        }

        nx = x - b - 1;

        if (nx >= 0 && !visit[nx]) {
            q.push({depth+1, nx});
            visit[nx] = true;
        }

        nx = x-1;

        if (nx >= 0 && !visit[nx]) {
            q.push({depth+1, nx});
            visit[nx] = true;
        }
        
    }
}
