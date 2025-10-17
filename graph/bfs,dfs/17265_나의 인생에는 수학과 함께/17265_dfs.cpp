#include <iostream>
#include <cstring>
#include <climits>
#include <string>

using namespace std;

struct st{
    int x;
    int y;
    int depth;
    string cal;
    int curr;
}typedef st;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int N;
int ansMin = INT_MAX;
int ansMax = -INT_MAX;
int shortDepth = 0;
bool visit[7][7];
string inp[7][7];

void dfs(st c);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1;i<=N; i++) {
        for (int j =1; j<=N; j++) {
            cin >> inp[i][j];
        }
    }

    memset(visit,false, sizeof(visit));
    shortDepth = N*2 - 2;

    st temp;
    temp.x = 1;
    temp.y = 1;
    temp.depth = 0;
    temp.curr = stoi(inp[1][1]);
    temp.cal = "";

    dfs(temp);

    cout << ansMax << " " << ansMin << " ";
    return 0;
}

void dfs(st c) {
    visit[c.x][c.y] = true;

    if (c.depth > shortDepth) return;
    if (c.depth == shortDepth && c.x == N && c.y == N) {
        ansMin = min(ansMin, c.curr);
        ansMax = max(ansMax, c.curr);
        return;
    }

    for (int i =0; i<4; i++) {
        int nx = c.x + dx[i];
        int ny = c.y + dy[i];

        if (nx >=1 && ny>=1 && nx<=N && ny <=N) {
            if(!visit[nx][ny]) {
                st n;
                
                if (c.cal == "") {
                    if (inp[nx][ny] == "+" || inp[nx][ny] == "-" || inp[nx][ny] == "*") {
                        visit[nx][ny] = true;
                        n.x = nx;
                        n.y = ny;
                        n.depth = c.depth + 1;
                        n.cal = inp[nx][ny];
                        n.curr = c.curr;
                        dfs(n);
                        visit[nx][ny] = false;
                    }
                } else {
                    if (inp[nx][ny] != "+" && inp[nx][ny] != "-" && inp[nx][ny] != "*") {
                        visit[nx][ny] = true;
                        n.x = nx;
                        n.y = ny;
                        n.depth = c.depth + 1;
                        n.cal = "";
                        if (c.cal == "+") {
                            n.curr = c.curr + stoi(inp[nx][ny]);
                        } else if(c.cal == "-") {
                            n.curr = c.curr - stoi(inp[nx][ny]);
                        } else{
                            n.curr = c.curr * stoi(inp[nx][ny]);
                        }
                        dfs(n);
                        visit[nx][ny] = false;
                    }
                }
            }
        }
    }
}
