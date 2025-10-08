#include <iostream>
#include <climits>

using namespace std;

int inp[5][5];
int r,c;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int ans = INT_MAX;

void dfs(int x, int y, int depth, int apple);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i =0; i<5; i++) {
        for (int j =0; j<5; j++) {
            cin >> inp[i][j];
        }
    }

    cin >> r >> c;
    inp[r][c] = -1;
    dfs(r,c,0,0);

    if (ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }
    
    return 0;
}

void dfs(int x, int y, int depth, int apple) {

    if (depth >= ans) {
        return;
    }
    
    if (apple == 3) {
        ans = min(ans, depth);
        return;
    }

    for (int i =0; i<4; i++) {
        int nx = x +dx[i];
        int ny = y +dy[i];

        if (nx>=0 && ny >=0 && nx<5 && ny <5) {
            if (inp[nx][ny] == 0) {
                inp[nx][ny] = -1;
                dfs(nx,ny,depth+1, apple);
                inp[nx][ny] = 0;
            } else if (inp[nx][ny] == 1) {
                inp[nx][ny] = -1;
                dfs(nx,ny,depth+1, apple+1);
                inp[nx][ny] = 1;
            }
        }
    }
}
