#include <iostream>
#include <vector>

using namespace std;

vector<int> inp;
vector<int> ans;

int N;

void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int temp;

    for (int i =0; i<N; i++) {
        cin >> temp;    
        inp.push_back(temp);
    }

    solve();

    cout << ans.size();
    
    return 0;
}

void solve() {

    ans.push_back(inp[0]);
    
    for (int i =1; i<N; i++) {
        if (ans.back() < inp[i]) {
            ans.push_back(inp[i]);
        } else {
            int start = 0;
            int end = ans.size()-1;
            int mid = 0;
            
            while(start <= end) {
                mid = (start+end)/2;
                int curr = ans[mid];

                if (curr < inp[i]) {
                    start = mid+1;
                } else {
                    end = mid-1;
                }
            }

            ans[start] = inp[i];
        }
    }
}
