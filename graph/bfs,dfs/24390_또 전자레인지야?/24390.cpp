#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct st{
    int time;
    int depth;
    bool start;
}typedef st;

queue<st> q;
bool visit[3602];
vector<string> result;

string ms;
int targetTime = 0;
int dx[] = {10, 60, 600};
int ans = 0;

void split(string str, char Delimiter);
void bfs();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> ms;

    split(ms, ':');

    targetTime = stoi(result[0]) * 60 + stoi(result[1]);

    memset(visit, false, sizeof(visit));

    bfs();

    cout << ans;
    
    return 0;
}

void split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    while(getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }
}

void bfs() {
    st temp;
    temp.time = 0;
    temp.depth = 0;
    temp.start = false;
    q.push(temp);
    visit[0] = true;

    while(!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp.time == targetTime) {
            if (temp.start) {
                ans = temp.depth;
            } else {
                ans = temp.depth + 1;
            }
            break;
        }

        if (temp.time == 0 || temp.start) {
            int nextTime = temp.time + 30;
            if (nextTime <= targetTime && !visit[nextTime]) {
                st n;
                n.time = nextTime;
                n.depth = temp.depth + 1;
                n.start = true;
                q.push(n);
                visit[nextTime] = true;
            }
        }

        for (int i =0; i<3; i++) {
            int nextTime = temp.time + dx[i];
            if (nextTime <= targetTime && !visit[nextTime]) {
                st n;
                n.time = nextTime;
                n.depth = temp.depth + 1;
                n.start = temp.start;
                q.push(n);
                visit[nextTime] = true;
            }
        }
    }
}
