#include <iostream>

using namespace std;

int inp[52][52];
int ans = 1;
int N,M,n;

void solve(int x, int y, int num);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    char c;

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            cin >> c;
            inp[i][j] = (int)(c-'0');
        }
    }

    n = min(N,M);

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            solve(i,j,inp[i][j]);
        }
    }

    cout << ans;
    
    return 0;
}

void solve(int x, int y, int num) {
    int nx = x;
    int ny = y;
    
    while(true) {
        nx++;
        ny++;

        if (nx >=N || ny >=M) break;
        
        if (inp[nx][ny] == num && inp[x][ny] == num && inp[nx][y] == num) {
            ans = max(ans, (nx-x+1) * (ny-y+1) );
        }
    }
}
