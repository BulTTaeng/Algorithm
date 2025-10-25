#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N,K;
int apple[18];
int dp[18][18];
vector<int> v[18];
int ans = 0;

void dfs(int x, int p);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int a,b;
    
    for(int i =0; i<N-1; i ++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i =0; i<N; i++) {
        cin >> apple[i];
    }

    dfs(0,-1);

    for (int i = 1; i <= K; i++) ans = max(ans, dp[0][i]);
    
    cout << ans;

    return 0;
}

void dfs(int x, int p) {
    dp[x][1] = apple[x];
    
    for(int i =0; i<v[x].size(); i++) {
        int nx = v[x][i];
        
        if (nx == p) continue;
        dfs(nx, x);

        int temp[18];
        memset(temp, 0, sizeof(temp));

        for (int j = 1; j <= K; j++) {
            for (int k = 1; j + k <= K; k++) {
                temp[j + k] = max(temp[j + k], dp[x][j] + dp[nx][k]);
            }
        }

        for (int j = 1; j <= K; j++) dp[x][j] = max(dp[x][j], temp[j]);
        
    }
}
