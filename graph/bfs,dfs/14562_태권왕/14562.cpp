#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int S, T, C;
bool visit[202][202];
queue< pair<int, pair<int,int>> > q;
int ans = 0;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> C;

    while(C--) {
        cin >> S >> T;
        memset(visit, false, sizeof(visit));
        q = queue< pair<int, pair<int,int>> >();
        bfs();

        cout << ans << "\n";
    }
    return 0;
}

void bfs() {
    q.push({T, {0,S}});
    visit[S][T] = true;

    while(!q.empty()) {
        int target = q.front().first;
        int depth = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (x == target) {
            ans = depth;
            break;
        }

        int nx = x * 2;
        int nTarget = target + 3;
        

        if (nx <= nTarget && !visit[nx][nTarget]) {
            q.push( {nTarget, {depth +1, nx} } );
            visit[nx][nTarget] = true;
        }

        nx = x + 1;

        if (nx <= target && !visit[nx][target]) {
            q.push( {target, {depth +1, nx} } );
            visit[nx][target] = true;
        }
        
    }
}
