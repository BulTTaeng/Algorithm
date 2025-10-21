#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> v[200001];
bool visit[200001];
int color[200001];
int ans = 0;

void dfs(int x, int parent);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        cin >> color[i];
    }

    int a,b;

    for (int i =0; i<N-1; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    memset(visit,false, sizeof(visit));

    dfs(1, 0);
    
    cout << ans;
    
    return 0;
}

void dfs(int x, int parent) {
    visit[x] = true;

    if (color[x] != color[parent]) {
        ans ++;
    }

    for (int i =0; i<v[x].size(); i++) {
        int nx = v[x][i];
        if(!visit[nx]) {
            dfs(nx, x);
        }
    }
}
