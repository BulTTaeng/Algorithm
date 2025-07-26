#include<iostream>
#include<cstring>

using namespace std;

int N, ans = 0;
int dp[1002];
int inp[1002];

void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[N];

    return 0;
}

void solve(){
    for (int i=1; i<=N; i++) {
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i-j] + inp[j] , dp[i]);
        }
    }
}
