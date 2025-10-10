#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<int> v[21];
bool visit[21];

int N, M, u, v2;
int ans = 0;

void dfs(int x, int couple);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i =0; i<M; i++) {
        cin >> u >> v2;
        v[u].push_back(v2);
        v[v2].push_back(u);
    }

    memset(visit, false, sizeof(visit));
    
    dfs(1,0);

    if (ans < N) ans++;
    cout << ans;
    
    return 0;
}

void dfs(int x, int couple) {
    ans = max(ans, couple);
    
    if (x >= N) return;

    if (visit[x]) {
        dfs(x+1, couple); // 이미 커플이 된 친구면 pass
    } else {
        visit[x] = true;
        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i];
            if(!visit[nx]) {
                visit[nx] = true; // 지금 친구(x)랑 커플 맺을 다른 친구 (nx) visit 처리
                dfs(x+1, couple + 2);
                visit[nx] = false;
            }
        }
        visit[x] = false;
        dfs(x+1, couple); // 커플 맺지 않는 case 처리
    }
}
