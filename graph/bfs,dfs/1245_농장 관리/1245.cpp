#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = {0,0,1,-1, -1, 1 , -1, 1 };
int ans = 0;
bool visit[102][72];
int inp[102][72];
int N, M;

bool dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i =0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            cin >> inp[i][j];
        }
    }

    memset(visit, false, sizeof(visit));
    
    for (int i =0; i<N; i++) {
        for (int j = 0; j<M; j++) {
            if (!visit[i][j]) {
                if(dfs(i,j)) {
                    ans++;
                }
            }
        }
    }

    cout << ans;
    
    return 0;
}

bool dfs(int x, int y) {
    visit[x][y] = true;
    bool isAnswer = true;

    for (int i =0; i<8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx>=0 && ny >=0 && nx<N && ny < M) {
            if (inp[nx][ny] > inp[x][y]) {
                isAnswer = false;
            } else if (!visit[nx][ny] && inp[nx][ny] == inp[x][y]) {
                if(!dfs(nx,ny)) {
                    isAnswer = false;
                }
            }
        }
    }

    return isAnswer;
}
