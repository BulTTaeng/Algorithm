#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n,m,Q;
queue<pair<int,int>> q;
int visit[1002];
vector<int> v[1002];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    int a,b;

    for (int i =0; i<m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cin >> Q;

    for (int i =0; i<Q; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);

        memset(visit, -1, sizeof(visit));
        bfs();

        for (int i =1; i<=n; i++) {
            cout << visit[i] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

void bfs() {
    q.push({0,1});
    visit[1] = 0;

    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i];

            if (visit[nx] == -1) {
                q.push({time +1, nx});
                visit[nx]= time+1;
            }
        }
    }
}
