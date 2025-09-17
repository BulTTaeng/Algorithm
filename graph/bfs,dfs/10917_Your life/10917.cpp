#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
queue<pair<int,int>> q;
vector<int> v[100001];
bool visit[100001];

int bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int x, y;
    
    for (int i =0; i<M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visit, false, sizeof(visit));

    cout << bfs();
    
    return 0;
}

int bfs() {
    q.push({1,0});
    visit[1] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int times = q.front().second;
        q.pop();

        if (x == N) {
            return times;
        }

        for (int i =0; i<v[x].size(); i++) {
            int next = v[x][i];

            if (next == N) {
                return times + 1;
            }
            
            if (!visit[next]) {
                q.push({next, times + 1});
                visit[next] = true;
            }
        }
    }

    return -1;
}
