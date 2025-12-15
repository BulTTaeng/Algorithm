#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
int N, M, m = 0;
int ans = 0;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    int temp;
    
    for (int i =0; i<N; i++) {
        cin >> temp;
        tree.push_back(temp);
        m = max(m, temp);
    }

    solve();

    cout << ans;
    
    return 0;
}

void solve() {
    int start = 0;
    int end = m;
    int mid = 0;
    
    while(start <= end) {
        mid = (start + end) / 2;
        long long sum = 0;
        for (int i =0; i<tree.size(); i++) {
            int diff = tree[i] - mid;
            if (diff > 0) sum += diff;
        }
        
        if (sum >= M) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        
    }
}
