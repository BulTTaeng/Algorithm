#include <iostream>
#include <cstring>

using namespace std;

int N;
long long ans = 0;
long long pibo[82];

void solve();

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    memset(pibo, 0 , sizeof(pibo));

    cin >> N;

    solve();

    cout << ans;
    return 0;
}

void solve(){
    if (N == 1) {
        ans = 4;
        return;
    }

    pibo[1] = 1;
    pibo[2] = 1;

    for (int i = 3; i<=N; i++) {
        pibo[i] = pibo[i-1] + pibo[i-2];
    }

    ans = pibo[N]*4 + pibo[N-1]*2;
    return;
}
