#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int N,M,S,E;
int dx[] = {-1, 1 };
queue<int> q;
vector<int> v[300002];
int visit[300002];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> S >> E;

    int x, y;
    
    for (int i =0; i<M; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    memset(visit, 0, sizeof(visit));

    bfs();

    cout << visit[E];
    
    return 0;
}

void bfs() {
    q.push(S);
    visit[S] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if (x == E) break;

        for (int i =0; i<v[x].size(); i++) {
            int nx = v[x][i];
            if(nx <=N && nx >=1 && visit[nx] == 0) {
                visit[nx] = visit[x] + 1;
                q.push(nx);
            } 
        }

        for (int i =0; i<2; i++) {
            int nx = x + dx[i];
            if(nx <=N && nx >=1 && visit[nx] == 0) {
                visit[nx] = visit[x] + 1;
                q.push(nx);
            } 
        }
    }
}
