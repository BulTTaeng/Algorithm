#include <iostream>

using namespace std;

int K;
int dpA[47] = {0,};
int dpB[47] = {0,};

void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> K; 

    solve();

    cout << dpA[K] << " " << dpB[K];

    return 0;
}

void solve() {
    dpA[0] = 1;
    dpB[0] = 0;

    for (int i =1; i<=K; i++) {
        dpA[i] = dpB[i-1];
        dpB[i] = dpA[i-1] + dpB[i-1];
    }
}
