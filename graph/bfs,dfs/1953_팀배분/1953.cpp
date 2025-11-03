#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[102];
int visit[102];
vector<int> teams[3];
int N;

void dfs(int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int a,b;

    for (int i =1; i<=N; i++) {
        cin >> a;

        for (int j=0; j<a; j++) {
            cin >> b;
            v[b].push_back(i);
            v[i].push_back(b);
        }
    }

    memset(visit, 0, sizeof(visit));
    
    for (int i = 1; i <= N; ++i) {
        if (visit[i] == 0) {
            visit[i] = 1;
            dfs(i);
        }
    }


    for (int i =1; i<=N; i++) {
        if (visit[i] == 1) {
            teams[1].push_back(i);
        } else {
            teams[2].push_back(i);
        }
    }

    sort(teams[1].begin(), teams[1].end());
    sort(teams[2].begin(), teams[2].end());

    cout << teams[1].size() << "\n";

    for (int i =0; i<teams[1].size(); i++) {
        cout << teams[1][i] << " ";
    }

    cout << "\n" << teams[2].size() << "\n"; 

    for (int i =0; i<teams[2].size(); i++) {
        cout << teams[2][i] << " ";
    }
    
    return 0;
}

void dfs(int x) {
    for (int i = 0; i < (int)v[x].size(); ++i) {
        int nx = v[x][i];
        if (visit[nx] == 0) {
            visit[nx] = 3 - visit[x];
            dfs(nx);
        }
    }
}
