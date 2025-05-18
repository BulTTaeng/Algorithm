#include <iostream>

using namespace std;

int N;
string S;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> S;

    for (int i = 0; i <= N-4; i++) {
        if (S.substr(i, 4) == "pPAp") {
            ans++;
            i += 3;  // 겹치지 않게 넘어가기
        }
    }

    cout << ans;

    return 0;
}
