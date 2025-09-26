#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <climits>

using namespace std;

int N, M;
queue<pair<int,int>> q;
bool visit[102];
int dis[102];
int sum[102];
vector<int> v[102];
int ans = 0;

void bfs(int start);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int x,y;
    
    for (int i =0; i<M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(sum, 0, sizeof(sum));

    for (int i =1; i<=N; i++) {
        bfs(i);
    }

    int minValue = INT_MAX;

    for (int i =1; i<=N; i++) {
        if (sum[i] < minValue) {
            ans = i;
            minValue = sum[i];
        }
    }

    cout << ans;
    
    return 0;
}

void bfs(int start) {
    memset(visit, false, sizeof(visit));
    memset(dis, 0, sizeof(dis));
    q = queue<pair<int,int>>();

    q.push({0,start});
    visit[start] = true;

    while(!q.empty()) {
        int depth = q.front().first;
        int curr = q.front().second;
        q.pop();

        for (int i =0; i<v[curr].size(); i++) {
            int nx = v[curr][i];
            if (!visit[nx]) {
                visit[nx] = true;
                dis[nx] = depth+1;
                q.push({depth+1, nx});
            }
        }
    }

    for (int i =1; i<=N; i++) {
        sum[start] += dis[i];
    }
}
