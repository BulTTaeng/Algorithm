#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, ans = 1;
vector<int> A;
int dp_in[1002];
int dp_de[1002];

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int temp;

    for (int i =0; i<N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    memset(dp_in, 0, sizeof(dp_in));
    memset(dp_de, 0, sizeof(dp_de));

    solve();

    cout << ans;

    return 0;
}

void solve() {
    for (int i = 0; i<N; i++) {
        dp_in[i] = 1; 
        for (int j = 0; j<i; j++) {
            if (A[j] < A[i]) dp_in[i] = max(dp_in[i], dp_in[j] + 1);
        }
    }

    for (int i = N-1; i>=0; i--) {
        dp_de[i] = 1;
        for (int j = N-1; j>i; j--) {
            if (A[j] < A[i]) dp_de[i] = max(dp_de[i], dp_de[j] + 1);
        }
    }

    for (int i =0; i<N; i++) {
        ans = max(dp_in[i]+dp_de[i]-1, ans);
    }
}
