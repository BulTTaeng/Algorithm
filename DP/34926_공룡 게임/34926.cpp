#include <iostream>
#include <cstring>

using namespace std;

int N,K;
bool dp[1000002];
char inp[1000002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        cin >> inp[i];
    }

    solve();

    if (dp[N]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

void solve(){
    memset(dp, false, sizeof(dp));
    
    dp[1] = true;
    
    for (int i=2; i<=N; i++) {
        if (inp[i] == '#') continue;

        dp[i] = dp[i-1];
        
        if (i>K) dp[i] = (dp[i] || dp[i-K]);
    }
}
