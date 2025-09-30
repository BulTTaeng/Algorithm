#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,S,D,F,B,K;

bool visit[100002];
queue<pair<int,int>> q;
int ans = -1;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> S >> D >> F >>B >> K;

    int temp;

    memset(visit, false, sizeof(visit));
    
    for (int i =0;i<K; i++) {
        cin >> temp;
        visit[temp] = true;
    }

    bfs();

    if (ans == -1) {
        cout << "BUG FOUND";
    } else {
        cout << ans;
    }
    
    return 0;
}

void bfs() {
    q.push({0, S});
    visit[S]  = true;

    while(!q.empty()) {
        int time = q.front().first;
        int x = q.front().second;
        q.pop();

        if (D == x) {
            ans = time;
            break;
        }

        int fx = x + F;
        int bx = x - B;

        if (fx>=1 && fx <=N ) {
            if (!visit[fx]) {
                q.push({time+1, fx});
                visit[fx] = true;
            }
        }

        if (bx>=1 && bx <=N ) {
            if (!visit[bx]) {
                q.push({time+1, bx});
                visit[bx] = true;
            }
        }
    }
}
