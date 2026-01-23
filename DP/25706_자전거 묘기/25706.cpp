#include <iostream>
#include <cstring>

using namespace std;

int N;
int inp[200002];
int dp[400004];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(inp, 0, sizeof(inp));
    
    cin >> N;

    for (int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    solve();

    for (int i =1; i<=N; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));
    
    dp[N] = 1;

    for (int i = N-1; i>=1; i--) {
        if(inp[i] == 0) dp[i] = dp[i+1] + 1;
        else {
            dp[i] = dp[i+inp[i]+1] +1; 
        }
    }
}
