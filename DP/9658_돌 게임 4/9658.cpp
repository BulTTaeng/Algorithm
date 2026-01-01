#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[1002]; // 0-> SK, 1 -> CY win

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    solve();

    if (dp[N] == 0) {
        cout << "SK";
    } else {
        cout << "CY";
    }
    
    return 0;
}

void solve() {
    memset(dp, 0, sizeof(dp));

    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 0;
    dp[5] = 0;

    for (int i = 6; i <= N; i++) {
		if (dp[i - 1] == 0 && dp[i - 3] == 0 && dp[i - 4] == 0) dp[i] = 1;
		else dp[i] = 0;
	}
}
