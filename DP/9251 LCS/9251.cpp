#include<iostream>
#include<string>
#include<cstring>

using namespace std;

string str1;
string str2;

int dp[1002][1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> str1 >> str2;

    memset(dp, 0, sizeof(dp));

    solve();

    cout << dp[str1.length()][str2.length()];

    return 0;
}

void solve() {
    for(int i=1; i<=str1.length(); i++) {
        for (int j=1; j<=str2.length(); j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}
