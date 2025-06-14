#include <iostream>
#include <vector>

using namespace std;

int N;
int A[1002];

vector<int> v;

void bSearch(int num);
void solve();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i=0; i<N; i++) {
        cin >> A[i];
    }

    solve();

    cout << v.size();
    return 0;
}

void bSearch(int num) {
    int start = 0;
    int end = v.size()-1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (v[mid] <= num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    v[start]= num;
}

void solve() {
    v.push_back(A[0]);

    for (int i=1; i<N; i++) {
        if (v.back() > A[i]) v.push_back(A[i]);
        else {
            bSearch(A[i]);
        }
    }
}

