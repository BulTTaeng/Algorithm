#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
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
queue<st> q;
int N;
int ansMin = INT_MAX;
int ansMax = -INT_MAX;
int shortDepth = 0;
string inp[7][7];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
  
    for (int i =1;i<=N; i++) {
        for (int j =1; j<=N; j++) {
            cin >> inp[i][j];
        }
    }

    shortDepth = N*2 - 2;

    bfs();

    cout << ansMax << " " << ansMin << " ";
    return 0;
}

void bfs() {
    st temp;
    temp.x = 1;
    temp.y = 1;
    temp.depth = 0;
    temp.curr = stoi(inp[1][1]);
    temp.cal = "";
    q.push(temp);

    while(!q.empty()) {
        st c = q.front();
        q.pop();
        if (c.depth > shortDepth) break;
        if (c.depth == shortDepth && c.x == N && c.y == N) {
            ansMin = min(ansMin, c.curr);
            ansMax = max(ansMax, c.curr);
            continue;
        }

        for (int i =0; i<4; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (nx >=1 && ny>=1 && nx<=N && ny <=N) {
                st n;
                
                if (c.cal == "") {
                    if (inp[nx][ny] == "+" || inp[nx][ny] == "-" || inp[nx][ny] == "*") {
                        n.x = nx;
                        n.y = ny;
                        n.depth = c.depth + 1;
                        n.cal = inp[nx][ny];
                        n.curr = c.curr;
                        q.push(n);
                    }
                } else {
                    if (inp[nx][ny] != "+" && inp[nx][ny] != "-" && inp[nx][ny] != "*") {
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
                        q.push(n);
                    }
                }
            }
        }
    }
}
