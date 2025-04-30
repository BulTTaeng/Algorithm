#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;
vector<int> v;

void permutation(int curr);

int main() {
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    cin >> N >> M;

    permutation(0);

    return 0;
}

void permutation(int depth) {
    if (depth == M) {
        for (int i =0; i<M; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i =1; i<=N; i++) {
        v.push_back(i);
        permutation(depth + 1);
        v.pop_back();
    }
}
