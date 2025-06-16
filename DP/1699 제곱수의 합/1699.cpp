#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int dp[100002];
int N;

vector<int> v;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[N];

    return 0;
}

void solve() {
    
    for (int i=1; i*i<=N; i++) {
        v.push_back(i*i);
    }

    dp[0] = 0;

    for (int i=1; i<=N; i++) {
        dp[i] = i;
        for (int j=0; j<v.size(); j++) {
            if (v[j] > i) break;
            dp[i] = min(dp[i], dp[i-v[j]] + 1);
        }
    }
}
