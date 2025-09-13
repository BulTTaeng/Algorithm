#include <iostream>

using namespace std;

int N, edge;
int root[101];
int ans =0;

void _union(int x, int y);
int _find(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> edge;

    int n1, n2;

    for (int i = 1; i<=N; i++) {
        root[i] = i;
    }

    for (int i =0; i<edge; i++) {
        cin >> n1 >> n2;
        _union(n1,n2);
    }

    for (int i =2;i<=N; i++) {
        if (_find(i) == _find(1)) ans ++;
    }

    cout << ans;

    return 0;
}

int _find(int x) {
    if (root[x] == x) return x;
    else {
        return root[x] = _find(root[x]);
    }
}

void _union(int x, int y) {
    if (x == y) return;

    x = _find(x);
    y = _find(y);

    root[y] = x;
}
