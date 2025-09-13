#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, edge;
vector<int> graph[101];
bool visit[101];
int ans = 0;
queue<int> q;

void BFS(int node);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    cin >> edge;

    int n1, n2;

    for (int i =0; i<edge; i++) {
        cin >> n1 >> n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }

    memset(visit, false, sizeof(visit));

    BFS(1);

    cout << ans;

    return 0;
}

void BFS(int node) {
    q.push(node);
    visit[node] = true;
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i =0; i<graph[curr].size(); i++) {
            int nextNode = graph[curr][i];
            if (!visit[nextNode]) {
                q.push(nextNode);
                ans++;
                visit[nextNode] = true;
            }
        }
    }
}
