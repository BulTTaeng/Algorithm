#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N,M;
vector<int> v[101];
bool visit[101];
string ans = "NO CYCLE";

void dfs(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int temp;
    memset(visit, false, sizeof(visit));

    for (int i =1; i<N; i++) {
        cin >> M;

        for (int j =0; j<M; j++) {
            cin >> temp;
            v[i].push_back(temp);
        }
    }
    visit[1] = true;
    dfs(1);

    cout << ans;
    
    return 0;
}

void dfs(int x) {
    if (ans == "CYCLE") return;

    for (int i =0; i<v[x].size(); i++) {
        int nx = v[x][i];

        if (visit[nx]) {
            ans = "CYCLE";
            return;
        } else {
            visit[nx] = true;
            dfs(nx);
            visit[nx] = false;
        }
    }
}
