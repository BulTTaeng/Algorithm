#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct st{
    int x = -1;
    int y = -1;
    vector<pair<int,int>> v;
}typedef st;

int T;
queue<st> q;
bool visit[8][9];
char startx, targetx;
int starty, targety;
st ans;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    char c;
    int temp;

    while(T--) {
        cin >> startx >> starty >> targetx >> targety;
        memset(visit, false, sizeof(visit));
        q = queue<st>();
        ans = st();
        
        bfs();

        if (ans.v.size() == 0) {
            cout << "Impossible" << "\n";
        } else {
            cout << ans.v.size() -1 << " ";
            for (int i = 0; i<ans.v.size(); i++) {
                char cc = ans.v[i].first + 'A';
                cout << (char)(ans.v[i].first + 'A') << " " << ans.v[i].second << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}

void bfs() {
    st temp;
    temp.x = (int)(startx - 'A');
    temp.y = starty;
    temp.v.push_back({temp.x, starty});
    q.push(temp);
    visit[temp.x][temp.y] = true;

    while(!q.empty()) {
        st curr = q.front();
        int x = curr.x;
        int y = curr.y;
        vector<pair<int,int>> v = curr.v;
        q.pop();

        if (v.size() > 4) {
            break;
        }


        if (x == (int)(targetx - 'A') && y == targety) {
            ans = curr;
            break;
        }

        int nx;
        int ny;

        for (int i =1; i<=8; i++) {
            nx = x + i;
            ny = y + i;

            if (nx<=7 && ny <= 8 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                st newSt;
                newSt.x = nx;
                newSt.y = ny;
                newSt.v = v;
                newSt.v.push_back({nx,ny});
                q.push(newSt);
            }
        }

        for (int i =1; i<=8; i++) {
            nx = x + i;
            ny = y - i;

            if (nx<=7 && ny >= 1 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                st newSt;
                newSt.x = nx;
                newSt.y = ny;
                newSt.v = v;
                newSt.v.push_back({nx,ny});
                q.push(newSt);
            }
        }

        for (int i =1; i<=8; i++) {
            nx = x - i;
            ny = y - i;

            if (nx>=0 && ny >= 1 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                st newSt;
                newSt.x = nx;
                newSt.y = ny;
                newSt.v = v;
                newSt.v.push_back({nx,ny});
                q.push(newSt);
            }
        }

        for (int i =1; i<=8; i++) {
            nx = x - i;
            ny = y + i;

            if (nx>=0 && ny <= 8 && !visit[nx][ny]) {
                visit[nx][ny] = true;
                st newSt;
                newSt.x = nx;
                newSt.y = ny;
                newSt.v = v;
                newSt.v.push_back({nx,ny});
                q.push(newSt);
            }
        }
    }
}
