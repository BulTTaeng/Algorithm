#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, start, des, ans = -1;
int num[10002];
bool visit[10002];

queue<pair<int,int>> q;

void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i =1; i<=N; i++) {
        cin >> num[i];
    }
    cin >> start >> des;

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;

    return 0;
}

void bfs() {
    q.push({start,0});

    while(!q.empty()) {
        int loc = q.front().first;
        int times = q.front().second;
        q.pop();

        if (loc == des) {
            ans = times;
            break;
        }
        
        int jump = num[loc];

        int i = 1;
        
        while (true) {
            int temp = jump * i;
            int rightLoc = loc + temp;
            
            if (rightLoc > N) break;
            
            if(!visit[rightLoc]) {
                q.push({rightLoc, times+1});
                visit[rightLoc] = true;
            }
            i++;
        }

        i = 1;

        while (true) {
            int temp = jump * i;
            int leftLoc = loc - temp;
            
            if (leftLoc <= 0) break;
            
            if(!visit[leftLoc]) {
                q.push({leftLoc, times+1});
                visit[leftLoc] = true;
            }
            i++;
        }
    }
}
