#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<int> x;
int t[100000002];

int solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    x.resize(N);
    for (int i =0; i<N; i++) {
        cin >> x[i];
    }

    memset(t, 0, sizeof(t));
    
    for (int i =0; i<N; i++) {
        cin >> t[x[i]];
    }

    sort(x.begin(), x.end(), greater<>());

    cout << solve();

    
    return 0;
}

int solve() {

    int time = 0;
    int loc = 0;
    
    for (int i =0; i<N; i++) {
        int currLoc = x[i];
        int outTime = t[currLoc];

        time += abs(currLoc - loc); // 이동시간
        if (time < outTime) {
            time += (outTime - time); // 대기 시간
        }
        loc = currLoc; // 위치 update
    }
    time += loc; // 마지막 위치에서 원점까지
    return time;
}
