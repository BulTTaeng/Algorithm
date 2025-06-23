#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans = 1;
vector<int> A;

vector<int> v1;
vector<int> v2;

int dp_1[1002];
int dp_2[1002];

void solve();
void bSearch(int target, vector<int>& v);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int temp;

    for (int i =0; i<N; i++) {
        cin >> temp;
        A.push_back(temp);
    }

    memset(dp_1, 0, sizeof(dp_1));
    memset(dp_2, 0, sizeof(dp_2));

    solve();

    cout << ans;

    return 0;
}

void bSearch(int target, vector<int>& v) {
    int start = 0;
    int end = v.size() -1;

    while(start <= end) {
        int mid = (start + end) / 2;

        if (v[mid] >= target) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    v[start] = target;
}

void solve() {

    v1.push_back(A[0]);
    dp_1[0] = 1;

    for (int i =1; i<N; i++) {
        if (A[i] > v1.back()) v1.push_back(A[i]);
        else bSearch(A[i], v1);
        dp_1[i] = v1.size();
    }

    reverse(A.begin(), A.end());

    v2.push_back(A[0]);
    dp_2[N-1] = 1;

    for (int i =1; i<N; i++) {
        if (A[i] > v2.back()) v2.push_back(A[i]);
        else bSearch(A[i], v2);
        dp_2[N-1-i] = v2.size();
    }

    for (int i=0; i<N; i++) {
        ans = max(ans, dp_1[i] + dp_2[i] - 1);
    }
}
