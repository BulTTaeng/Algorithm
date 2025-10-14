#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> v[1001];
int visit[1001];
bool ans = true;

int N, M, T;

void dfs(int x, int prev);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    int a,b;

    while(T--) {
        cin >> N >> M;

        for (int i =1; i<=N; i++) {
            visit[i] = 0;
            v[i].clear();
        }
        ans = true;
        
        for (int i =0; i<M; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }

        for (int i =1; i<=N; i++) {
            if (visit[i] == 0) dfs(i, 0);
        }

        if (ans) {
            cout << "possible" << "\n";
        } else {
            cout << "impossible" << "\n";
        }
    }
    
    return 0;
}

void dfs(int x, int prev) {

    if (ans == false) return;
    
    int color = 0;
    if(prev == 1) {
        color = 2;
    } else {
        color = 1; 
    }

    visit[x] = color;

    for (int i =0; i<v[x].size(); i++) {
        int nx = v[x][i];

        if (visit[nx] == 0) {
            dfs(nx,color);
        } else if (visit[nx] == color) {
            ans = false;
            return;
        }
    }
}
