#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int A, K;
int ans = 0;
queue<pair<int,int>> q;
bool visit[1000001];

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> A >> K;

    memset(visit, false, sizeof(visit));
    
    bfs();

    cout << ans;
    
    return 0;
}

void bfs() {
    q.push({A,0});

    while(!q.empty()) {
        pair<int,int> curr = q.front();
        int value = curr.first;
        int time = curr.second;
        q.pop();
        visit[value] = true;

        if (value == K) {
            ans = time;
            break;
        } else {
            if (value <K && !visit[value+1]) q.push({value+1, time+1});
            if ((value *2 <= K) && !visit[value*2]) q.push({value*2, time+1});
        }
    }
}
