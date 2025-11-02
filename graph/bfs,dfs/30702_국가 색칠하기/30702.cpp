#include <iostream>
#include <cstring>

using namespace std;

bool visit[52][52];
char inp[52][52];
char target[52][52];
int N,M;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

string ans = "YES";

void dfs(int x, int y, char color, char nColor);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            cin >> inp[i][j];
        }
    }

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            cin >> target[i][j];
        }
    }

    memset(visit,false, sizeof(visit));

    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            if (inp[i][j] != target[i][j] && !visit[i][j]) {
                dfs(i,j,inp[i][j],target[i][j]);
            }
        }
    }


    for (int i =0; i<N; i++) {
        for (int j =0; j<M; j++) {
            if (inp[i][j] != target[i][j]) {
                ans = "NO";
                break;
            }
        }
        if (ans == "NO") break;
    } 

    cout << ans;
    
    return 0;
}

void dfs(int x, int y, char color, char nColor) {
    visit[x][y] = true;
    inp[x][y] = nColor;

    for (int i =0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx>=0 && ny>=0 && nx<N && ny<M) {
            if (!visit[nx][ny] && inp[nx][ny] == color) {
                dfs(nx, ny, color, nColor);
            }
        }
    }
}
