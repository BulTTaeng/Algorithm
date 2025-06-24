#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int N, K;
int W[102];
int V[102];

int dp[100002];

int ans = 0;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    memset(dp, 0, sizeof(dp));
    memset(W, 0, sizeof(W));
    memset(V, 0, sizeof(V));
    
    for (int i =1; i<=N; i++) {
        cin >> W[i] >> V[i];
    }

    solve();

    cout << dp[K];

    return 0;
}

void solve() {    
    for (int i=1; i<=N; i++) {
        int currW = W[i];
        int currV = V[i];
        for (int j=K; j>=currW; j--) {
            dp[j] = max(dp[j], dp[j-currW] + currV);
        }
    }
}
