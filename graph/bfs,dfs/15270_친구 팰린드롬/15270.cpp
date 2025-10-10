#include <iostream>
#include <vector>
#include <cstring>

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
    if (x > N) {
        ans = max(ans, couple);
        return;
    }

    if (visit[x]) {
        dfs(x+1, couple);
        return;
    }
    
    visit[x] = true;
    dfs(x+1, couple);
    visit[x] = false;

    for (int i =0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(!visit[nx]) {
            visit[nx] = true;
            visit[x] = true;
            dfs(x+1, couple +2);
            visit[nx] = false;
            visit[x] = false;
        }
    }
}
