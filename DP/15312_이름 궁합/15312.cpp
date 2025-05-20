#include <iostream>
#include <cstring>

using namespace std;

int score[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

string A, B;
int ans = 0;
int dp[4002][4002];
string total = "";

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> A >> B;

    memset(dp, 0 , sizeof(dp));

    for (int i =1; i<=A.length()*2; i+=2) {
        dp[0][i] = score[int(A[i]) - int('A')];
        dp[0][i+1] = score[int(B[i] - int('A'))];
    }

    for(int i = 1; i<=A.length()*2 - 2; i++) {

        for (int j = 1; j<=A.length() * 2 - i; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j+1];
        }
    }

    cout << dp[A.length()-2][1] << dp[A.length()-2][2];
    return 0;
}
