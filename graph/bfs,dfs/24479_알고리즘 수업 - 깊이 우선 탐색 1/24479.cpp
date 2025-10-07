#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

priority_queue<int,vector<int>, greater<>> pq[100001];
int N,M,R;
int visit[100001];
int order = 1;

void dfs(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> R;

    int a,b;
    
    for (int i =0; i<M; i++) {
        cin >> a >> b;
        pq[a].push(b);
        pq[b].push(a);
    }

    memset(visit, 0, sizeof(visit));

    dfs(R);

    for (int i =1; i<=N; i++) {
        cout << visit[i] << "\n";
    }
    
    return 0;
}

void dfs(int x) {
    visit[x] = order;
    order++;

    while(!pq[x].empty()) {
        int nx = pq[x].top();
        pq[x].pop();

        if (visit[nx] == 0) {
            dfs(nx);
        }
    }
}
