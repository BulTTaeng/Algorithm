#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> v[5002];
queue<int> q;
bool visit[5002];
long long cost[5002];
long long ans;

void bfs();

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

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push(1);
    visit[1] = true;
    cost[1] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i].first;
            int dist = v[x][i].second;
            
            if (!visit[nx]) {
                visit[nx] = true;
                cost[nx] = cost[x] + dist;
                q.push(nx);
            }
        }
    }

    for (int i =1; i<=N; i++) {
        ans = max(ans, cost[i]);
    }
}
