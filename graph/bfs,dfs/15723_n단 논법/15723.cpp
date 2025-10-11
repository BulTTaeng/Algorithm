#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N,M;
vector<int> v[27];
bool visit[27];
int n1, n2;
string temp;

bool dfs(int start, int target);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i =0; i<N; i++) {
        for (int j=0; j<3; j++) {
            cin >> temp;
            if (j == 0) {
                n1 = (int)(temp[0]-'a');
            } else if (j == 2) {
                n2 = (int)(temp[0]-'a');
            }
        }
        v[n1].push_back(n2);
    }

    cin >> M;

    for (int i =0; i<M; i++) {
        for (int j=0; j<3; j++) {
            cin >> temp;
            if (j == 0) {
                n1 = (int)(temp[0]-'a');
            } else if (j == 2) {
                n2 = (int)(temp[0]-'a');
            }
        }
        memset(visit,false, sizeof(visit));
        
        if (dfs(n1,n2)) {
            cout << "T" << "\n";
        } else {
            cout << "F" << "\n";
        }
    }
    return 0;
}

bool dfs(int start, int target) {
    if (start == target) {
       return true; 
    }

    bool founded = false;
    
    visit[start] = true;
    
    for(int i =0; i<v[start].size(); i++) {
        int nx = v[start][i];

        if (!visit[nx]) {
            visit[nx] = true;
            founded = dfs(nx, target);
            if (founded) return true;
            visit[nx] = false;
        }
    }

    visit[start] = true;

    return founded;
}
