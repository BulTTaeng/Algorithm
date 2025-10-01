#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N,K;
vector<int> v[100001];
vector<int> apple;
queue<pair<int,int>> q;
bool visit[100001];
int ans = 0;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int a,b;
    
    for (int i =0 ;i<N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 0; i < N; i++) {
        cin >> a;
        apple.push_back(a);
    }
    
    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push({0,0});
    visit[0] = true;

    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second;
        q.pop();

        if (time > K) continue;

        ans += apple[x];

        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i];
            if (!visit[nx]) {
                visit[nx] = true;
                q.push({time+1, nx});
            }
        }
    }
}
