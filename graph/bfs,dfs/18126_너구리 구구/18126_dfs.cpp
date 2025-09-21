#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> v[5002];
bool visit[5002];
long long ans = 0;

void dfs(int curr, long long dist);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int a,b,c;

    for (int i =0; i<N-1; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }

    memset(visit, false, sizeof(visit));

    visit[1] = true;
    
    dfs(1,0);

    cout << ans;
    
    return 0;
}

void dfs(int curr, long long dist) {
    ans = max(ans, dist);

    for (int i =0; i<v[curr].size(); i++ ) {
        int nx = v[curr][i].first;
        long long ndist = v[curr][i].second;

        if (!visit[nx]) {
            visit[nx] = true;
            dfs(nx, dist + ndist);
        }
    }
}
