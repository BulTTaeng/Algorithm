#include <iostream>
#include <cstring>

using namespace std;

int farm[102][102];
bool visit[102][102];
int N,M,K;
int dx[] = { -1,1, 0,0};
int dy[] = {0,0,1,-1};
int ans = 0;
int k;

void dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i =0; i<N; i++) {
        for (int j =0; j<N; j++) {
            cin >> farm[i][j];
        }
    }

    memset(visit, false, sizeof(visit));

    ans = M;

    for (int i =0; i<N; i++) {
        for (int j =0; j<N; j++) {
            if (farm[i][j] == 0) {
                k = K;
                dfs(i,j);
            }
        }
    }

    bool possible = true;

    for (int i =0; i<N; i++) {
        for (int j =0; j<N; j++) {
            if (farm[i][j] == 0) {
                possible = false;
                break;
            }
        }
    }
    
    if (possible && ans != M) {
        cout << "POSSIBLE" << "\n";
        cout << ans;
    } else {
        cout << "IMPOSSIBLE";
    }
    
    return 0;
}

void dfs(int x, int y) {
    if(ans == 0 && k==K) return;
    
    farm[x][y] = 1;
    
    if(k == K) {
        ans--;
    }

    for (int i =0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx>=0 && ny>=0 && nx<N && ny<N) {
            if (farm[nx][ny] == 0 && k != 1){
                farm[nx][ny] = 1;
                k--;
                dfs(nx,ny);
            }
        }
    }
}
