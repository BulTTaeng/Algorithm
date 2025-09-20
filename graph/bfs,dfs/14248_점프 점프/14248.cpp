#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, S, ans = 0;
int A[100002];
bool visit[100002];
queue<int> q;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        cin >> A[i];
    }

    cin >> S;

    memset(visit, false, sizeof(visit));
    
    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push(S);
    visit[S] = true;
    ans = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        int nx = x + A[x];
        if (nx <= N && !visit[nx]) {
            ans++;
            visit[nx] = true;
            q.push(nx);
        }

        nx = x - A[x];
        if (nx >= 1 && !visit[nx]) {
            ans++;
            visit[nx] = true;
            q.push(nx);
        }
    }
}
