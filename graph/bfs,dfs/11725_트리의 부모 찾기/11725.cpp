#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool visit[100002];
int parent[100002];
vector<int> v[100002];

void dfs(int curr);

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n ,x ,y;

    cin >> n;

    memset(visit , false ,sizeof(visit));

    for(int i =1; i<n; i++){
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i =2; i<=n; i++){
        cout << parent[i] << "\n";
    }
    return 0;
}

void dfs(int curr){

    if(visit[curr]){
        return ;
    }

    visit[curr] = true;

    for(int i =0; i<v[curr].size(); i++){
        dfs(v[curr][i]);
        parent[v[curr][i]] = curr;
    }

    return;
}
