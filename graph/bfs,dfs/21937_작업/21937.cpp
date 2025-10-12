#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N,M,X;
vector<int> v[100001];
queue<pair<int,int>> q;
bool visit[100001];
int ans = 0;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int a,b;
    
    for (int i =0; i<M; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }

    cin >> X;

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    visit[X] = true;
    q.push( {0,X} );

    while(!q.empty()) {
        int depth = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i];

            if (!visit[nx]) {
                ans ++;
                visit[nx] = true;
                q.push({depth+v[x].size(), nx});
            }
        }
        
    }
}
