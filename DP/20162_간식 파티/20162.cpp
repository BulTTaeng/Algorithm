#include <iostream>
#include <vector>

using namespace std;

int N;
int dp[1002];
int inp[1002];
int ans = 0;

void binary(int num);
void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    inp[0] = 0;

    for (int i =1; i<=N; i++) {
        cin >> inp[i];
    }

    solve();

    cout << ans;
    
    return 0;
}

void solve(){
    dp[0] = 0;
    for (int i =1; i<=N; i++) {
        dp[i] = inp[i];
        for (int j =1; j<i; j++) {
            if (inp[j] < inp[i]) {
                dp[i] = max(dp[i], dp[j] + inp[i]);
            }
        }
        ans = max(dp[i], ans);
    }
}
