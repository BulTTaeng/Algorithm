#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

double good[102];
double bad[102];
double per[4];

int N, feel;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> feel;

    for (int i =0; i<4; i++) {
        cin >> per[i];
    }

    solve();

    cout << round(good[N] * 1000) << "\n" << round(bad[N] * 1000);
    
    return 0;
}

void solve() {
    memset(good, 0, sizeof(good));
    memset(bad, 0, sizeof(bad));
    
    if (feel == 0) {
        good[1] = per[0];
        bad[1] = per[1];
    } else {
        good[1] = per[2];
        bad[1] = per[3];
    }

    for (int i =2; i<=N; i++) {
        good[i] = (good[i-1] * per[0]) + (bad[i-1] * per[2]);
        bad[i] = (good[i-1] * per[1]) + (bad[i-1] * per[3]);
    }
}
