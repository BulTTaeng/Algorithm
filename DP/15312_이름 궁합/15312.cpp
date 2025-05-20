#include <iostream>
#include <vector>

using namespace std;

int score[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};

string A, B;
int len = 0;
vector<int> dp;
string total = "";

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> A >> B;
    len = A.length() * 2;

    for (int i =0; i<A.length(); i++) {
        dp.push_back(score[int(A[i]) - int('A')]);
        dp.push_back(score[int(B[i] - int('A'))]);
    }

    while (dp.size() > 2) {
        vector<int> next;
        for (int i =0; i<dp.size()-1; i++) {
            next.push_back( (dp[i] + dp[i+1]) % 10 );
        }
        dp = move(next);
    }

    cout << dp[0] << dp[1];
    return 0;
}
