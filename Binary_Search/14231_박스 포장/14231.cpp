#include <iostream>
#include <vector>

using namespace std;

int inp[5002];
vector<int> ans;
int N;

void binary(int target);
void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i =0; i<N; i++) {
        cin >> inp[i];
    }

    solve();

    // for (int i =0; i<ans.size(); i++) {
    //     cout << ans[i] << " ";
    // }

    cout << ans.size();
    
    return 0;
}

void binary(int target){
    int start = 0;
    int end = ans.size() - 1;
    int mid = 0;

    while(start <= end) {
        mid = (start+end) / 2;
        int midValue = ans[mid];

        if (midValue < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    ans[start] = target;
}

void solve() {
    for (int i =0; i<N; i++) {
        int curr = inp[i];
        
        if (ans.empty()) {
            ans.push_back(curr);
        } else {
            int last = ans.back();
            if (last < curr) {
                ans.push_back(curr);
            } else {
                binary(curr);
            }
        }
    }
}
