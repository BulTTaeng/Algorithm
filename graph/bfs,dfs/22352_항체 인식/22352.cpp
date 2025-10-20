#include <iostream>
#include <cstring>

using namespace std;

int N, M;
bool visit[32][32];
int inp[32][32];
int result[32][32];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
string ans = "YES";
int val = 0;
int rVal = 0;

void dfs(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i =0; i<N;i++) {
        for (int j =0; j<M; j++) {
            cin >> inp[i][j];
        }
    }

    for (int i =0; i<N;i++) {
        for (int j =0; j<M; j++) {
            cin >> result[i][j];
        }
    }

    int x =-1,y =-1;

    for (int i =0; i<N;i++) {
        for (int j =0; j<M; j++) {
            if (inp[i][j] != result[i][j]) {
                x = i;
                y = j;
                val = inp[i][j];
                rVal = result[i][j];
                break;
            }
        }
        if (x != -1) break;
    }

    if (x == -1 && y == -1) {
        cout << ans;
    } else {
        memset(visit , false ,sizeof(visit));
    
        dfs(x,y);
    
        for (int i =0; i<N;i++) {
            for (int j =0; j<M; j++) {
                if (inp[i][j] != result[i][j]) {
                    ans = "NO";
                    break;
                }
            }
        }
    
        cout << ans;
    }
    
    return 0;
}

void dfs(int x, int y) {
    inp[x][y] = rVal;
    visit[x][y] = true;

    for (int i =0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >=0 && ny >= 0 && nx <N && ny<M) {
            if (!visit[nx][ny] && inp[nx][ny] == val) {
                dfs(nx, ny);
            }
        }
    }
}
